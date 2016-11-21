// Copyright 2016 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../../MultiScene/ITMMultiSceneManager.h"
#include "../Interface/ITMVisualisationEngine.h"

namespace ITMLib {

	template<class TVoxel, class TIndex>
	class ITMMultiVisualisationEngine
	{
	public:
		virtual ~ITMMultiVisualisationEngine(void) {}

		virtual ITMRenderState* CreateRenderState(const ITMScene<TVoxel, TIndex> *scene, const Vector2i & imgSize) const = 0;

		virtual void PrepareRenderState(const ITMMultiSceneManager_instance<TVoxel, TIndex> & sceneManager, ITMRenderState *state) = 0;

		//skip "FindVisibleBlocks"

		virtual void CreateExpectedDepths(const ORUtils::SE3Pose *pose, const ITMIntrinsics *intrinsics, ITMRenderState *renderState) const = 0;
		virtual void RenderImage(const ORUtils::SE3Pose *pose, const ITMIntrinsics *intrinsics, ITMRenderState *renderState,
			ITMUChar4Image *outputImage, IITMVisualisationEngine::RenderImageType type) const = 0;
	};
}

