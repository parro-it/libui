#include "../../ui.h"
#include <stdio.h>
#include <stdlib.h>

uiWindow *mainwin;

int onClosing(uiWindow *w, void *data)
{
	uiQuit();
	return 1;
}

int main(void)
{
	uiInitOptions o;
	uiLabel *l;
	const char *err;

	memset(&o, 0, sizeof(uiInitOptions));
	err = uiInit(&o);
	if (err != NULL)
	{
		fprintf(stderr, "%s\n", err);
		uiFreeInitError(err);
		return 1;
	}

	mainwin = uiNewWindow("HelanBean Test", 640, 480, 0);

	l = uiNewLabel("Helloworld!你好，世界！");
	uiWindowSetChild(mainwin, uiControl(l));

	uiWindowOnClosing(mainwin, onClosing, NULL);
	uiControlShow(uiControl(mainwin));
	uiMain();
	return 0;
}
