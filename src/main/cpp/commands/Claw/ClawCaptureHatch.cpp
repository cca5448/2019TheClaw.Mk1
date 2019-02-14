#include "commands/Claw/ClawCaptureHatch.h"
#include "Robot.h"
#include "RobotMap.h"

ClawCaptureHatch::ClawCaptureHatch(){
	Requires(Robot::claw.get());
}

void ClawCaptureHatch::Initialize(){
    Robot::claw->MoveClawToCaptureHatch();
}

void ClawCaptureHatch::Execute(){
}

bool ClawCaptureHatch::IsFinished(){
	static double target = CLAW_POT_VAL_CH;
	printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawCaptureHatch::End(){
	Robot::claw->StopClaw();
}

void ClawCaptureHatch::Interrupted(){
	End();
}

