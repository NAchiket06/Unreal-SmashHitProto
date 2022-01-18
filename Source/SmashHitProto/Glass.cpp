// Fill out your copyright notice in the Description page of Project Settings.


#include "Glass.h"

// Sets default values
AGlass::AGlass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);


	

}

// Called when the game starts or when spawned
void AGlass::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentHit.AddDynamic(this,&AGlass::DisableCollider);
}

// Called every frame
void AGlass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGlass::DisableCollider(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit)
{
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	UE_LOG(LogTemp,Warning,TEXT("Disabled Collision"));
}


