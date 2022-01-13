// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(FVector(1,0,0) * MovementSpeed * DeltaTime);

	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookRight"),this,&APlayerCharacter::LookRightRotation);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APlayerCharacter::LookUpRotation);

}

void APlayerCharacter::LookRightRotation(float value)
{
	AddControllerYawInput(value);
}

void APlayerCharacter::LookUpRotation(float value)
{
	AddControllerPitchInput(-value);
}

