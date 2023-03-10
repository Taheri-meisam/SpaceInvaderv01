// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);
	TimeLived += DeltaTime;

	if (TimeLived > TimeBeforeDestroy)
	{
		this->Destroy();
	}

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	UE_LOG(LogTemp, Warning, TEXT(" Overlapped"));
	//// if it hits enemy destroy enemy and this actor 
	//if (OtherActor->IsA(AEnemy::StaticClass()))
	//{
	//	Cast<AEnemy>(OtherActor)->ImHit(); //OtherActor->Destroy();
	//	//PartikkelFX:
	//	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletFireFX, GetTransform(), true);

	//	//SoundFX
	//	UGameplayStatics::PlaySoundAtLocation(GetWorld(), BulletFireSound, GetActorLocation());

	//	//Destroy Bullet:
	//	Destroy();
	//}


}