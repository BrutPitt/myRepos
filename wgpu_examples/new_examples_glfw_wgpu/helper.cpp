
#if defined(IMGUI_IMPL_WEBGPU_BACKEND_DAWN)
/// DAWN Validation Layer callback: reason for device loss
static void ImGui_ImplWGPU_DAWN_DeviceLostCallback_Helper(const wgpu::Device&, wgpu::DeviceLostReason reason, wgpu::StringView message)
{
    const char* reasonName = "";
    switch (reason) {
    case wgpu::DeviceLostReason::Unknown:           reasonName = "Unknown";         break;
    case wgpu::DeviceLostReason::Destroyed:         reasonName = "Destroyed";       break;
    case wgpu::DeviceLostReason::CallbackCancelled: reasonName = "InstanceDropped"; break;
    case wgpu::DeviceLostReason::FailedCreation:    reasonName = "FailedCreation";  break;
    default:                                        reasonName = "UNREACHABLE";     break;
    }
    printf("%s device message: %s\n", reasonName, message.data);
}

/// DAWN Validation Layer callback: error type
static void ImGui_ImplWGPU_DAWN_ErrorCallback_Helper(const wgpu::Device&, wgpu::ErrorType type, wgpu::StringView message)
{
    const char* errorTypeName = "";
    switch (type) {
    case wgpu::ErrorType::Validation:  errorTypeName = "Validation";      break;
    case wgpu::ErrorType::OutOfMemory: errorTypeName = "Out of memory";   break;
    case wgpu::ErrorType::Unknown:     errorTypeName = "Unknown";         break;
    case wgpu::ErrorType::Internal:    errorTypeName = "Internal";        break;
    default:                           errorTypeName = "UNREACHABLE";     break;
    }
    printf("%s error: %s\n", errorTypeName, message.data);
}
#else
/// WGPU LOG callback: print information (stderr) based on WGPULogLevel_xxx required level
static void ImGui_ImplWGPU_WGPU_LogCallback_Helper(WGPULogLevel level, WGPUStringView message, void *userdata)
{
    const char *level_str = "";
    switch (level) {
    case WGPULogLevel_Error: level_str = "error"; break;
    case WGPULogLevel_Warn:  level_str = "warn";  break;
    case WGPULogLevel_Info:  level_str = "info";  break;
    case WGPULogLevel_Debug: level_str = "debug"; break;
    case WGPULogLevel_Trace: level_str = "trace"; break;
    default:                 level_str = "unknown_level";
    }
    fprintf(stderr, "[wgpu] [%s] %.*s\n", level_str, (int) message.length, message.data);
}
#endif

/// Print Adapter info
///@param[in]  adapter const WGPUAdapter & : reference to acquired and valid WGPUAdapter
///@note The function prints: "selected Adapter - drivers version, BackendType (#)" used
void ImGui_ImplWGPU_PrintAdapterInfo_Helper(const WGPUAdapter &adapter)
{
    WGPUAdapterInfo info = {};
    wgpuAdapterGetInfo(adapter, &info);
    printf("Using: %.*s - %.*s, BackendType (%u)\n", (int) info.device.length, info.device.data, (int) info.description.length, info.description.data, info.backendType);
}

/// Check Surface Texture Status
///@param[in]  fb_width  int : current FrameBuffer width
///@param[in]  fb_height int : current FrameBuffer height
///@note with "recoverable state" there will be an attempt to re-Configure the Surface, with "unrecoverable state" aborts program
static WGPUTexture ImGui_ImplWGPU_CheckSurfaceTextureStatus_Helper(int fb_width, int fb_height)
{
    WGPUSurfaceTexture surfaceTexture;
    wgpuSurfaceGetCurrentTexture(wgpu_surface, &surfaceTexture);

    switch ( surfaceTexture.status )
    {
#if defined(__EMSCRIPTEN__) && !defined(IMGUI_IMPL_WEBGPU_BACKEND_DAWN)
        case WGPUSurfaceGetCurrentTextureStatus_Success:
            break;
#else
        case WGPUSurfaceGetCurrentTextureStatus_SuccessOptimal:
            break;
        case WGPUSurfaceGetCurrentTextureStatus_SuccessSuboptimal:
#endif
        case WGPUSurfaceGetCurrentTextureStatus_Timeout:
        case WGPUSurfaceGetCurrentTextureStatus_Outdated:
        case WGPUSurfaceGetCurrentTextureStatus_Lost:
        // if the status is NOT Optimal let's try to reconfigure the surface
        {
            if (surfaceTexture.texture)
                wgpuTextureRelease(surfaceTexture.texture);
            if ( fb_width > 0 && fb_height > 0 )
            {
                wgpu_surface_configuration.width  = fb_width;
                wgpu_surface_configuration.height = fb_height;

                wgpuSurfaceConfigure(wgpu_surface, &wgpu_surface_configuration);
            }
            return nullptr;
        }
        // Unrecoverable errors
#if defined(IMGUI_IMPL_WEBGPU_BACKEND_DAWN)
        case WGPUSurfaceGetCurrentTextureStatus_Error:
#else   // IMGUI_IMPL_WEBGPU_BACKEND_WGPU
        case WGPUSurfaceGetCurrentTextureStatus_OutOfMemory:
        case WGPUSurfaceGetCurrentTextureStatus_DeviceLost:
#endif
        case WGPUSurfaceGetCurrentTextureStatus_Force32:
            // Fatal error
            printf("Unrecoverable Error check_surface_texture status=%#.8x\n", surfaceTexture.status);
            abort();

        default:            // should never be reached
            printf("Unexpected Error check_surface_texture status=%#.8x\n", surfaceTexture.status);
            abort();
    }
    return surfaceTexture.texture;
}

