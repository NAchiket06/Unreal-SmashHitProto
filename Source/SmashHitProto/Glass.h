// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Glass.generated.h"

UCLASS()
class SMASHHITPROTO_API AGlass : public AActor
{
	GENERATED_BODY()
	
public:	
	AGlass();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	void DisableCollider(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

