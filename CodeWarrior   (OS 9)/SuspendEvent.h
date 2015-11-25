/*	File:		SuspendEvent.h	Contains:		Written by: C.K. Haun		Copyright:	Copyright � 1991-1999 by Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.	Change History (most recent first):				7/21/1999	Karl Groethe	Updated for Metrowerks Codewarror Pro 2.1				*/#include <Types.h>#include <memory.h>#include <Packages.h>#include <Errors.h>#include <quickdraw.h>#include <fonts.h>#include <dialogs.h>#include <windows.h>#include <menus.h>#include <events.h>#include <OSEvents.h>#include <Desk.h>#include <diskinit.h>#include <OSUtils.h>#include <resources.h>#include <toolutils.h>#include <AppleEvents.h>#include <EPPC.h>#include <GestaltEqu.h>#include <PPCToolbox.h> #include <Processes.h>#include <Balloons.h>#include <aliases.h>/* windowControl is the structure attached to every window I create (in the refCon *//* field) that contains all the information I need to know about the window. *//* data, procedure pointers for controlling, and anything else gets put in this *//* struct.  That makes my windows autonomous */struct windowControl {    unsigned long windowID;                                 /* master ID number  */    ProcPtr drawMe;                                         /* content drawing procedure pointer */	ProcPtr clickMe;										/* content click routine */    ProcPtr closeMe;                                        /* document close procedure pointer */	ProcPtr sizeMe;											/* size procedure */    AliasHandle fileAliasHandle;                            /* alias for this document */    Boolean windowDirty;	Handle generalData;										/* cast to whatever you need as you need it */};typedef struct windowControl windowControl, *windowCPtr, **windowCHandle;enum {kDocWindowResID = 128,kMyDocumentWindow = 1000};/* menu enums */enum {kMBarID = 128};enum {kAppleMenu = 128,kFileMenu,kEditMenu,kToolsMenu};/* file menu enums */enum {kNewItem = 1,kOpenItem,kCloseItem,kSaveItem,kSaveAsItem,kFileBlank1,kPageSetupItem,kPrintItem,kFileBlank2,kQuitItem};/* general purpose enums */enum {kResumeMask=1,kSampHelp=129,kAboutBox=128,kHelpString=128,kBadSystem=130};enum {kMinHeight = 200};enum {kGeneralStrings=128};enum {kPendingWords1=1,kPendingWords2};#define kSuspCreator 0x11171915#define kFredDocType 'FRED'#define kAlDocType 'AL  '