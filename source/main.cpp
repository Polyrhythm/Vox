// ******************************************************************************
// Filename:    main.cpp
// Project:     Vox
// Author:      Steven Ball
//
// Purpose:
//   The main entry point for the application. Creates the initial instances of
//   the container classes, iterates the game loop, polls events/input and 
//   detects for game closure to cleanup the with the destruction.
// 
// Revision History:
//   Initial Revision - 27/10/15
//
// Copyright (c) 2005-2016, Steven Ball
// ******************************************************************************

#include "VoxGame.h"

int main(void)
{
  /* force Mac OSX to be on OpenGL 3.2+ */
  /*glfwInit();*/
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  /*glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

	/* Load the settings */
	VoxSettings* m_pVoxSettings = new VoxSettings();
	m_pVoxSettings->LoadSettings();
	m_pVoxSettings->LoadOptions();

	/* Initialize and create the VoxGame object */
	VoxGame* pVoxGame = VoxGame::GetInstance();
	pVoxGame->Create(m_pVoxSettings);

	/* Loop until the user closes the window or application */
	while (!pVoxGame->ShouldClose())
	{
		/* Poll input events*/
		pVoxGame->PollEvents();

		/* Update joysticks */
		pVoxGame->UpdateJoySticks();

		/* Update */
		pVoxGame->Update();

		/* PreRender */
		pVoxGame->PreRender();

		/* Render */
		pVoxGame->Render();
	}

	/* Cleanup */
	pVoxGame->Destroy();

	/* Exit */
	exit(EXIT_SUCCESS);
}
