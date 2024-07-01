// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "RaccoonGameJamCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogCharacter, Log, All);

UCLASS(config=Game)
class ARaccoonGameJamCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PickupItemAction;

public:
	ARaccoonGameJamCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/* Called to Pickup Items */
	void PickupItem(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable) int GetTrashByIndex(int index);

	UFUNCTION(BlueprintCallable) void AddTrashByIndex(int index);
	
	UFUNCTION(BlueprintCallable) void RemoveTrashByIndex(int index);

	UFUNCTION(BlueprintCallable) void RemoveMultipleTrash(int index, int amount);

	UFUNCTION(BlueprintCallable) void ResetTrashInventory();

	UFUNCTION(BlueprintCallable)
	float GetTrashSum();

private:

	UFUNCTION(BlueprintCallable) void SelectTrash(UObject* trash);

	UFUNCTION(BlueprintCallable) void DeSelectTrash(UObject* trash, bool fromCollision);

	APlayerController* PlayerController;

	UObject* selectedTrash;

	UPROPERTY(VisibleAnywhere, category = "trashInventory", meta = (Tooltip = "the structure that holds trash to be scored or removed"))
	TArray<int> trashInventory;

	UPROPERTY(VisibleAnywhere,category = "trashInventory", meta = (Tooltip = "the value of each piece of trash in the trash inventory"))
	TArray<float> trashValues;
	//the sum value of all trash 
	float trashSum ;

	
};

