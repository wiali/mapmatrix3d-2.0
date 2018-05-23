 #pragma once
#include "InterfaceBaseDrawer.h"
#include "BaseUserEvent.h"
#include "operationState.h"

class COsgDrawSinglePtHandler : virtual public CBaseUserEvent
{
public:
	COsgDrawSinglePtHandler(osgViewer::Viewer *viewer, osg::Group *root, osg::ref_ptr<osg::Group> editSceneGroup) : CBaseUserEvent(viewer)
	{
		mViewer = viewer;
		mRoot = root;
		mEditSceneGroup = editSceneGroup;

		InterfaceBaseDrawerFactory IBaseDrawerFactory;
		IBaseDrawer = IBaseDrawerFactory.create();

		isActivated = false;
	}

protected:
	virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa);

	virtual void ClickDrawSinglePtOperate(std::vector<osg::Vec3d> &vecWorldCoord, osg::Vec3d worldPt, osg::Vec4d color, double size, osg::ref_ptr<osg::Group> drawGroup, 
		osg::Matrix worldMatrix);										

	virtual void BackSpaceReverseSinglePtOperate(std::vector<osg::Vec3d> &vecWorldCoord, osg::ref_ptr<osg::Group> drawGroup);

	virtual void UpdateActivatedStatus(std::vector<OperatingState> vecOpState);

protected:
	std::vector<osg::Vec3d> vecWorldCoord;

	osgViewer::Viewer *mViewer;
	osg::Group *mRoot;
	osg::ref_ptr<osg::Group> mEditSceneGroup;

	InterfaceBaseDrawer* IBaseDrawer;

	bool isActivated;
};

