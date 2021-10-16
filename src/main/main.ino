#include <SimpleFOC.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

// Setup AS56000 analog position sensor
MagneticSensorAnalog sensor = MagneticSensorAnalog(A1, 14, 1020);

// Setup 3-phase BLDC driver
BLDCDriver3PWM driver = BLDCDriver3PWM(9, 5, 6, 8);

// Setup 7-pole BLDC motor
BLDCMotor motor = BLDCMotor(7);


void setup() {

  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("");
  
  // Initialize magenetic sensor hardware
  sensor.init();

  driver.voltage_power_supply = 12;
  driver.voltage_limit = 6;
  driver.init();

  motor.linkSensor(&sensor);
  motor.linkDriver(&driver);
  motor.controller = MotionControlType::angle;
  motor.PID_velocity.P = 0.2;
  motor.PID_velocity.I = 20;
  motor.PID_velocity.D = 0.001;
  // jerk control it is in Volts/s or Amps/s
  // for most of applications no change is needed 
  motor.PID_velocity.output_ramp = 1e6;
  
  // velocity low pass filtering time constant
  motor.LPF_velocity.Tf = 0.01;
  
  // angle loop controller
  motor.P_angle.P = 20;
  motor.P_angle.I = 0; // usually set to 0  - P controller is enough
  motor.P_angle.D = 0; // usually set to 0  - P controller is enough
  // acceleration limit
  motor.P_angle.output_ramp = 1e6;
  
  // motion control limits
  // angle loop velocity limit
  motor.velocity_limit = 10;
  motor.init();

  motor.initFOC();
  Serial.println("Motor instantiated");
}

void loop() {

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  motor.loopFOC();
  motor.move(g.gyro.x);
}
