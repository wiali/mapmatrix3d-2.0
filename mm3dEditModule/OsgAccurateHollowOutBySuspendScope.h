#pragma once
#include "OsgClipBySupendScope.h"


class COsgAccurateHollowOutBySuspendScope : public COsgClipBySupendScope
{
public:

protected:
	virtual void startClipModelByScope(std::vector<osg::MatrixTransform*> vecTrans, std::string headOutputFilePath, std::string inFilePath,
		std::vector<CScope> vecClipScope, CStProgressSetter stProgressSetter, bool isInside);

	virtual void showHintClipping(InterfaceSigEventCallBack* iSigEventCallBack);

	virtual void showHintFinishClipping(InterfaceSigEventCallBack* iSigEventCallBack);
};

