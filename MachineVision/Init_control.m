%%%  Trajectory_Ctrl_sim
clear

%Initial condition
ModelInit_PosE = [0, 0, 0];  %Initial position
ModelInit_VelB = [0, 0, 0];  %Initial velocity
ModelInit_AngEuler = [0, 0, 0];  %Initial Euler angle
ModelInit_RateB = [0, 0, 0];  %Initial angular velocity
ModelInit_Rads = 0; %Initial motor speed(rad/s)

%UAV model parameter
ModelParam_uavMass = 1.4; %Mass of UAV(kg)
ModelParam_uavJxx = 0.0211;
ModelParam_uavJyy = 0.0219; 
ModelParam_uavJzz = 0.0366;
%Moment of inertia matrix
ModelParam_uavJ= [ModelParam_uavJxx, 0, 0;...
    0, ModelParam_uavJyy, 0;...
    0, 0, ModelParam_uavJzz];
ModelParam_uavType = int8(3); %X-type quadrotor，refer to "SupportedVehicleTypes.pdf" for specific definitions
ModelParam_uavMotNumbs = int8(4);  %Number of motors
ModelParam_uavR = 0.225;   %Body radius(m)
ModelParam_uavCd = 0.055;   %Damping coefficient(N/(m/s)^2)
ModelParam_uavCCm = [0.0035 0.0039 0.0034]; %Damping moment coefficient vector(N/(m/s)^2)

ModelParam_motorCr = 1148; %Motor throttle-speed curve slope(rad/s)
ModelParam_motorWb = -141.4;  %Motor speed-throttle curve constant term(rad/s)
ModelParam_motorT = 0.02;  %Motor inertia time constant(s)
ModelParam_motorJm = 0.0001287;  %Moment of inertia of motor rotor + propeller(kg.m^2)
ModelParam_motorMinThr = 0.05;  %Motor throttle dead zone(kg.m^2)
%M=Cm*w^2
ModelParam_rotorCm = 1.779e-07;  %Rotor torque coefficient(kg.m^2)
%T=Ct**w^2
ModelParam_rotorCt = 1.105e-05;  %Rotor thrust coefficient(kg.m^2)

%Environment Parameter
ModelParam_envGravityAcc = 9.8;  %Gravity acceleration(m/s^2)
ModelParam_envLongitude = 116.259368300000;  
ModelParam_envLatitude = 40.1540302;         
ModelParam_GPSLatLong = [ModelParam_envLatitude ModelParam_envLongitude];  %Latitude and longitude
ModelParam_envAltitude = -41.5260009765625;  %Reference height, down is positive
ModelParam_BusSampleRate = 0.001;  %Model sampling rate;

%Constant value
RAD2DEG = 57.2957795;
DEG2RAD = 0.0174533;
%throttle when UAV is hovering
THR_HOVER = 0.609;

%% Initial condition
% ModelInit_PosE = [0, 0, -100];
% ModelInit_VelB = [0, 0, 0];
% ModelInit_AngEuler = [0, 0, 0];
% ModelInit_RateB = [0, 0, 0];
% ModelInit_Rads = 557.142;
%% control parameter
% attitude PID parameters
Kp_PITCH_ANGLE = 6.5;
Kp_PITCH_AngleRate = 0.1;
Ki_PITCH_AngleRate = 0.02;
Kd_PITCH_AngleRate = 0.001;
Kp_ROLL_ANGLE = 6.5;
Kp_ROLL_AngleRate = 0.1;
Ki_ROLL_AngleRate = 0.02;
Kd_ROLL_AngleRate = 0.001;

Kp_YAW_AngleRate = 0.3;
Ki_YAW_AngleRate = 0.1;
Kd_YAW_AngleRate = 0.00;
% position PID Parameters
Kpxp = 1.0;
Kpyp = 1.0;
Kpzp = 4.0;
Kvxp = 2.5; Kvxi = 0.4; Kvxd = 0.01;
Kvyp = 2.5; Kvyi = 0.4; Kvyd = 0.01;
Kvzp = 0.45; Kvzi = 0.01; Kvzd = 0.005;

% integral saturation
Saturation_I_RP_Max = 0.3;
Saturation_I_RP_Min = -0.3;
Saturation_I_Y_Max = 0.2;
Saturation_I_Y_Min = -0.2;
Saturation_I_ah = 3.43;
Saturation_I_az = 5;
% max control angle, default 35deg
MAX_CONTROL_ANGLE_ROLL = 35;
MAX_CONTROL_ANGLE_PITCH  = 35;
% max control angle rate, rad/s 
MAX_CONTROL_ANGLE_RATE_PITCH = 220;
MAX_CONTROL_ANGLE_RATE_ROLL = 220;
MAX_CONTROL_ANGLE_RATE_Y = 200;
% max control speed, m/s
MAX_CONTROL_VELOCITY_XY = 5;
MAX_CONTROL_VELOCITY_Z = 3;
% throttle amplitude
MAX_MAN_THR = 0.95;
MIN_MAN_THR = 0.05;
%% trajectory paramters
%圆形轨迹
%确定航轨点数目
num_points =100;
heigh = 3;%设置高度
%预先生成储存x、y位置的向量
x = zeros(num_points,1);
y = zeros(num_points,1);
z = ones(num_points,1);
%存储期望的轨迹点
desired = zeros(num_points+2,4);
desired_pos_series = zeros(num_points+2,3);
desired_yaw = zeros(num_points+1,1);
desired_pos_series(1,:)=[0,0,0];
desired_pos_series(2,:)=[0,0,heigh];
%生成轨迹点
for i = 1:num_points
    x(i) = 10*cos(2*pi*i/num_points);
    y(i) = 10*sin(2*pi*i/num_points);
end
%给轨迹点赋值
desired_pos_series(3:end,1) = x(:,1);
desired_pos_series(3:end,2) = y(:,1);
desired_pos_series(3:end,3) = z(:,1)*heigh;
desired(:,1:3) = desired_pos_series(:,:);
desired(2:end,4) = desired_yaw;
figure(1)
plot3(desired_pos_series(:,1),desired_pos_series(:,2),desired_pos_series(:,3),'-r');
grid on
xlabel('x');
ylabel('y');
zlabel('z');
title("圆形轨迹仿真结果");
xlim([-15,15]);
ylim([-15,15]);
zlim([0,5]);


