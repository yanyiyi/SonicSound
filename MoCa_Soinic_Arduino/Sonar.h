class Sonar
{
    private:
        int triggerPin, echoPin, duration;
        long timeOut;
    public:
        Sonar(byte _triggerPin, byte _echoPin) {
            pinMode(_triggerPin, OUTPUT);
            pinMode(_echoPin, INPUT);
            triggerPin = _triggerPin;
            echoPin = _echoPin;
            timeOut = 30000;
            // 3000 µs = 50cm // 30000 µs = 5 m
        }
        Sonar(byte _triggerPin, byte _echoPin, long _timeOut) {
            pinMode(_triggerPin, OUTPUT);
            pinMode(_echoPin, INPUT);
            triggerPin = _triggerPin;
            echoPin = _echoPin;
            timeOut = _timeOut;
        }
        int timing() {
            digitalWrite(triggerPin, LOW);
            delayMicroseconds(2);
            digitalWrite(triggerPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(triggerPin, LOW);
            duration = pulseIn(echoPin, HIGH, timeOut);
            return (duration == 0) ? timeOut : duration;
        }
        int ranging() {
            return (int)(timing() / 28.5 / 2);
        }
};
