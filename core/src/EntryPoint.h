#pragma once

#if defined(ABC_WINDOWS)
#elif defined(ABC_LINUX)
#elif defined(ABC_MACOS)
#error unsuported as of yet...
#else
#error unsuported...
#endif

#if defined(ABC_DEBUG)
#elif defined(ABC_RELEASE)
#elif defined(ABC_DIST)
#endif

extern ABC_Name::Application* ABC_Name::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace ABC_Name {
	int Main(int argc, char** argv) {
		Log::Init();

		while (g_ApplicationRunning) {
			ABC_Name::Application* app = ABC_Name::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}
}

#if defined(ABC_WINDOWS) && defined(ABC_DIST)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	return ABC_Name::Main(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return ABC_Name::Main(argc, argv);
}

#endif // 0
