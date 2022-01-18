// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "Glass.h"
#include "Components/StaticMeshComponent.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"
// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	// When Bullet is intialized, sit its intital force
	Mesh->AddForce(GetActorForwardVector() * InitialForce);

	// HIT EVENTS OF THE BULLET
	Mesh->OnComponentHit.AddDynamic(this,&ABullet::OnBulletHit);
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::OnBulletHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit)
{
	CheckIfGlassHit(OtherActor);	
}

void ABullet::CheckIfGlassHit(AActor* OtherActor)
{
	AGlass* GlassPane = Cast<AGlass>(OtherActor);
	if(GlassPane != nullptr)
	{
		Mesh->AddForceAtLocation(HitForce,GetActorLocation());
		//	OtherActor->Destroy();=
	}
}

