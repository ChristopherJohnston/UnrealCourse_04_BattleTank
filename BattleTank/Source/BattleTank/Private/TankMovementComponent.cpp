// Copyright CPJ 2018

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    auto ClampedThrow = FMath::Clamp<float>(Throw, -1, 1);
    LeftTrack->SetThrottle(ClampedThrow);
    RightTrack->SetThrottle(ClampedThrow);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    auto ClampedThrow = FMath::Clamp<float>(Throw, -1, 1);
    LeftTrack->SetThrottle(ClampedThrow);
    RightTrack->SetThrottle(-ClampedThrow);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto TankForward = GetOwner()->GetActorForwardVector();

    auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
    IntendMoveForward(ForwardThrow);

    auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
    IntendTurnRight(RightThrow);
}


