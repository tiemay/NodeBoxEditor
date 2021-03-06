#ifndef EDITOR_HPP_INCLUDED
#define EDITOR_HPP_INCLUDED

#include "common.hpp"
#include "EditorState.hpp"
#include "NodeEditor.hpp"
#include "Project.hpp"

class Editor : public IEventReceiver
{
public:
	Editor();
	bool run(IrrlichtDevice *irr_device, Configuration *conf);
	virtual bool OnEvent(const SEvent &event);

	EditorState *state;
	irr::IrrlichtDevice *device;
private:
	// Helper functions
	int currentWindow;
	ISceneNode *target;
	ISceneNode *pivot;
	ICameraSceneNode *camera[4];
	void LoadScene();
};

#endif
