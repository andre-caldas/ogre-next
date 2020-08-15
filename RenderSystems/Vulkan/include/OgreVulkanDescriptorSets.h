/*
  -----------------------------------------------------------------------------
  This source file is part of OGRE
  (Object-oriented Graphics Rendering Engine)
  For the latest info, see http://www.ogre3d.org

Copyright (c) 2000-present Torus Knot Software Ltd

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
  -----------------------------------------------------------------------------
*/

#ifndef _OgreVulkanDescriptorSetTexture_H_
#define _OgreVulkanDescriptorSetTexture_H_

#include "OgreVulkanPrerequisites.h"

#include "OgreHeaderPrefix.h"

#include "vulkan/vulkan_core.h"

namespace Ogre
{
    struct VulkanDescriptorSetSampler
    {
        FastArray<VkDescriptorImageInfo> mSamplers;
        VkWriteDescriptorSet mWriteDescSet;
        VulkanDescriptorSetSampler( const DescriptorSetSampler &descSet );
    };

    struct VulkanDescriptorSetUav
    {
        FastArray<VkDescriptorImageInfo> mTextures;
        FastArray<VkDescriptorBufferInfo> mBuffers;
        VkWriteDescriptorSet mWriteDescSets[2];

        VulkanDescriptorSetUav( const DescriptorSetUav &descSetUav );

        void destroy( const DescriptorSetUav &descSetUav );
    };

    struct Range
    {
        uint32 location;
        uint32 length;
    };
    struct VulkanTexRegion
    {
        VkImageView *textures;
        Range range;
        ShaderType shaderType;
    };
    struct VulkanBufferRegion
    {
        VkBuffer *buffers;
        VkDeviceSize *offsets;
        Range range;
        ShaderType shaderType;
    };

    struct VulkanDescriptorSetTexture
    {
        FastArray<VulkanTexRegion> textures;
        FastArray<VulkanBufferRegion> buffers;

        VkImageView *textureViews;
        VkSampler *textureSamplers;
        size_t numTextureViews;
    };
}  // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif  // #ifndef _OgreVulkanDescriptorSetTexture_H_
