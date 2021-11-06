#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

class FMyProjectEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void AddMenuExtension(FMenuBuilder& Builder);
	void GenerateToolBarButton(FToolBarBuilder& Builder);
	void ShowMySimpleWidget();
	TSharedRef<SDockTab> OnShowMySimpleWidget(const FSpawnTabArgs& SpawnTabArgs);
};