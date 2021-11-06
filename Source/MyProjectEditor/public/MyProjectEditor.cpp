#include "MyProjectEditor.h"
#include "LevelEditor.h"
#include "SMySimpleWidget.h"

IMPLEMENT_MODULE(FMyProjectEditorModule, MyProjectEditor);

static const FName MySimpleWidgetTabName("MySimpleWidget");

#define LOCTEXT_NAMESPACE "SMySimpleWidget"

void FMyProjectEditorModule::StartupModule()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MySimpleWidgetTabName, FOnSpawnTab::CreateRaw(this, &FMyProjectEditorModule::OnShowMySimpleWidget))
		.SetDisplayName(LOCTEXT("MySimpleWidget", "MySimpleWidget"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	//add menu content
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, MakeShareable(new FUICommandList), FMenuExtensionDelegate::CreateRaw(this, &FMyProjectEditorModule::AddMenuExtension));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	//add toolbar button
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, MakeShareable(new FUICommandList), FToolBarExtensionDelegate::CreateRaw(this, &FMyProjectEditorModule::GenerateToolBarButton));
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FMyProjectEditorModule::ShutdownModule()
{
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MySimpleWidgetTabName);
}

void FMyProjectEditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(
		LOCTEXT("ShowMySimpleWidget", "ShowMySimpleWidget"), 
		LOCTEXT("ShowMySimpleWidgetToolTip", "ShowMySimpleWidgetToolTip"), 
		FSlateIcon(), 
		FUIAction(FExecuteAction::CreateRaw(this, &FMyProjectEditorModule::ShowMySimpleWidget)));
}

void FMyProjectEditorModule::GenerateToolBarButton(FToolBarBuilder& Builder)
{
	//simple toolbar button
	Builder.AddToolBarButton(
		FUIAction(FExecuteAction::CreateRaw(this, &FMyProjectEditorModule::ShowMySimpleWidget)),
		NAME_None,
		LOCTEXT("SimpleWidget", "SimpleWidget"),
		LOCTEXT("SimpleWidgetToolTip", "ShowMySimpleWidgetToolTip")
	);
}

void FMyProjectEditorModule::ShowMySimpleWidget()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MySimpleWidgetTabName);
}

TSharedRef<SDockTab> FMyProjectEditorModule::OnShowMySimpleWidget(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab).TabRole(ETabRole::NomadTab)
		[
			SNew(SMySimpleWidget)
		];
}

#undef LOCTEXT_NAMESPACE
