#pragma once
#include "VKHelpers.h"
#include <tuple>

namespace vk
{
	struct gpu_formats_support
	{
		bool d24_unorm_s8 : 1;
		bool d32_sfloat_s8 : 1;
	};

	gpu_formats_support get_optimal_tiling_supported_formats(VkPhysicalDevice physical_device);
	VkFormat get_compatible_depth_surface_format(const gpu_formats_support &support, rsx::surface_depth_format format);

	std::tuple<VkFilter, VkSamplerMipmapMode> get_min_filter_and_mip(u8 min_filter);
	VkFilter get_mag_filter(u8 mag_filter);
	VkSamplerAddressMode vk_wrap_mode(u32 gcm_wrap);
	float max_aniso(u32 gcm_aniso);
	VkComponentMapping get_component_mapping(u32 format, u8 swizzle_mask);
	VkPrimitiveTopology get_appropriate_topology(rsx::primitive_type& mode, bool &requires_modification);
}