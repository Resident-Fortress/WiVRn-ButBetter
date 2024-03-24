/*
 * WiVRn VR streaming
 * Copyright (C) 2024  Guillaume Meunier <guillaume.meunier@centraliens.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "xr/hand_tracker.h"
#include <render/scene_data.h>
#include <openxr/openxr.h>

struct hand_model
{
	xr::hand_tracker& hand;

	node_handle root_node;
	std::vector<node_handle> joints;

	hand_model(xr::hand_tracker & hand, const std::filesystem::path & gltf_path, scene_loader& loader, scene_data& scene);

	void apply(XrSpace world_space, XrTime predicted_display_time);
};
