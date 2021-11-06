// Fill out your copyright notice in the Description page of Project Settings.


#include "SMySimpleWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SMySimpleWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySimpleWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock).Text(LOCTEXT("HW", "Hello World !"))
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
