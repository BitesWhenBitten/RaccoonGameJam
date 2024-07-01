// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelUI.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONGAMEJAM_API ULevelUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void Setup();

	UFUNCTION()
	void GameOver(bool bGameWon);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual bool Initialize() override;


protected:


	UPROPERTY(BlueprintReadonly)
	float TimeRemaining;

	UPROPERTY(BlueprintReadonly)
	bool isGamePlaying = true;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* EndText;

	UPROPERTY(meta = (BindWidget))
	class UButton* RetryButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

private:

	class ARaccoonGameJamGameMode* GameMode;

	UFUNCTION()
	void RetryLevelButtonClicked();
	UFUNCTION()
	void QuitGameButtonClicked();

	void TurnOnButtons();

	void GameWon();
	void GameLost();

	void SetInputToPaused();
	void SetInputToInPlay();


};
