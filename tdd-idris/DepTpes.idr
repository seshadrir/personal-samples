import Data.Vect

data PowerSource = Petrol | Pedal | Electric


data Vehicle : PowerSource -> Type where 
  Bicycle : Vehicle Pedal
  UniCycle : Vehicle Pedal
  MotorCycle : (fuel : Nat) -> Vehicle Petrol
  Car : (fuel : Nat) -> Vehicle Petrol
  Bus : (fule : Nat) -> Vehicle Petrol
  Tram : (battery : Nat) -> Vehicle Electric
  ElecCar : (battery : Nat) -> Vehicle Electric


wheels : Vehicle power -> Nat
wheels Bicycle = 2 
wheels (Car fuel) = 4 
wheels (Bus fule) = 4 
wheels UniCycle = 1 
wheels (MotorCycle fuel) = 2 
wheels (Tram battery) = 8 
wheels (ElecCar battery) = 4
 

refuel : Vehicle Petrol -> Vehicle Petrol 
refuel (Car fuel) = Car 100 
refuel (Bus fule) = Bus 200
refuel Bicycle impossible
refuel UniCycle impossible
refuel (MotorCycle fuel) = MotorCycle 10 

recharge : Vehicle Electric -> Vehicle Electric
recharge (Tram battery) = Tram 10000 
recharge (ElecCar battery) = ElecCar 1000
recharge Bicycle impossible
recharge UniCycle impossible
recharge (Car fuel) impossible
recharge (Bus fuel) impossible
recharge (MotorCycle fule) impossible




listTake : Nat -> List a -> List a
listTake Z xs = []
listTake (S k) [] = [] 
listTake (S k) (x :: xs) = x :: listTake k xs

vecTake : (k : Nat) -> Vect (k+n) elem -> Vect k elem
vecTake Z xs = [] 
vecTake (S k) (x :: xs) = x :: vecTake k xs 
