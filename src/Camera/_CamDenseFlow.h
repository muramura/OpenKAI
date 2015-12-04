/*
 * CameraOpticalFlow.h
 *
 *  Created on: Aug 21, 2015
 *      Author: yankai
 */

#ifndef SRC_CAMDENSEFLOW_H_
#define SRC_CAMDENSEFLOW_H_

#include "../Base/common.h"
#include "../Base/cvplatform.h"
#include "../Camera/CamFrame.h"
#include "../Base/_ThreadBase.h"
#include "stdio.h"

using namespace cv;
using namespace cv::cuda;
using namespace std;

#define TRD_INTERVAL_DENSEFLOW 1000

namespace kai
{

class _CamDenseFlow: public _ThreadBase
{
public:
	_CamDenseFlow();
	virtual ~_CamDenseFlow();

	bool init(JSON* pJson, string camName);
	bool start(void);

	inline bool isFlowCorrect(Point2f u);
	Vec3b computeColor(float fx, float fy);
	void drawOpticalFlow(const Mat_<float>& flowx, const Mat_<float>& flowy, Mat& dst, float maxmotion);
	void generateFlowMap(const GpuMat& d_flow);

private:
	fVector4 detect(void);
	void update(void);
	static void* getUpdateThread(void* This)
	{
		((_CamDenseFlow*) This)->update();
		return NULL;
	}

public:
	fVector4		m_flow;
	GpuMat		m_GFlowMat;
	CamFrame*	m_pFlowFrame;
	CamFrame*	m_pShowFlow;

	int	m_width;
	int m_height;

	Mat m_uFlowMat;
	Mat m_flowX;
	Mat m_flowY;

	Ptr<cuda::FarnebackOpticalFlow> m_pFarn;
};

} /* namespace kai */

#endif /* SRC_CAMDENSEFLOW_H_ */