<img width="3188" height="1202" alt="frame (3)" src="https://github.com/user-attachments/assets/517ad8e9-ad22-457d-9538-a9e62d137cd7" />


# BuzzBed Buddy – "A smart pillow that listens."


## Basic Details
### Team Name: TechSpark


### Team Members
- Team Lead: AMINA SALI - NSS COLLEGE OF ENGINEERING PALAKKAD
- Member 2: ALAN BABU N - NSS COLLEGE OF ENGINEERING PALAKKAD


### Project Description
Ever wanted your pillow to judge your sleeping habits?
Meet the BuzzBed Buddy — a pillow that listens to your snoring and shakes its head (well, your head) in disapproval. It doesn’t stop your snoring forever, but it will annoy you just enough to make you roll over and pretend you don’t snore. Perfect for anyone who thinks peace and quiet are overrated.

### The Problem 
   Snoring — nature’s way of turning peaceful nights into a live concert nobody asked for. While the snorer enjoys a free front-row ticket to dreamland, everyone else is stuck listening to a remix of chainsaws, motorboats, and foghorns. Over time, this “nightly soundtrack” can be more than just annoying; it can hint at serious health issues like sleep apnea, which sneakily steals energy, focus, and even heart health.

 Most anti-snoring gadgets are either torture devices in disguise or bank-account bullies. Wearables can feel like sleeping with a mini robot strapped to your face, and loud alarms just make everyone in the room grumpy. Clearly, the world is begging for a gentler, friendlier, and cheaper way to give snorers a polite nudge—without turning bedtime into a full-blown wake-up call for the whole neighborhood.

### The Solution 

 A pillow with superpowers — it hears you snore and politely tells you to “shhh” without using words. Inside, there’s a sneaky little sound sensor that waits for your midnight chainsaw to start. The moment you begin your greatest hits album of Zzz & Rrrrr, a tiny vibration motor gives you a gentle nudge, like a sleepy friend saying, “Hey buddy, roll over.”

 No masks, no alarms, no wrestling with weird gadgets in the middle of the night. Just a comfy pillow that quietly keeps the peace while you sleep like royalty — minus the royal trumpet fanfare in your nose. It’s cheap, friendly, and might just save your relationships… or at least your roommate’s sanity.
## Technical Details
### Technologies/Components Used
For Software:
-Ardunio IDE

For Hardware:
1. Arduino Board – Acts as the brain of your project (Arduino Uno or Nano recommended).
2. KY-038 Sound Sensor – Detects the snoring sound.
3. Flat Button-Type Vibration Motor – Gently vibrates the pillow when snoring is detected.
4. Relay Module or Transistor – To control the vibration motor safely.
5. Jumper Wires – For all the connections between components.
6. Breadboard – For prototyping the circuit before final assembly.
7. Power Supply / Battery Pack – To run the Arduino and motor (e.g., 9V battery or rechargeable pack).
8. Pillow / Cushion – The cozy home for all the magic.

 Implementation
For Hardware:

# Schematic & Circuit

<img width="1920" height="1080" alt="Screenshot (15)" src="https://github.com/user-attachments/assets/c8407cf4-eace-4b13-90d1-ffe326619664" />
"Arduino Anti-Snoring Pillow Circuit: Sound Sensor Triggers Vibration Motor"


# Build Photos
components
![WhatsApp Image 2025-08-09 at 06 34 04_ab6327f2](https://github.com/user-attachments/assets/42b59c09-0dff-4f85-9c84-b13e38ec84ce)

![WhatsApp Image 2025-08-09 at 06 40 08_15d85ccc](https://github.com/user-attachments/assets/3e794950-d174-4efb-88e8-7c9f10137a76)

![WhatsApp Image 2025-08-09 at 06 40 10_dce24e97](https://github.com/user-attachments/assets/08096c43-fa9e-4622-b8e2-a26f27dc0cd1)

![WhatsApp Image 2025-08-09 at 06 40 10_af0129ef](https://github.com/user-attachments/assets/eddc1c94-91cc-4068-b085-8e482919dedc)

![WhatsApp Image 2025-08-09 at 06 40 11_30c0c46a](https://github.com/user-attachments/assets/a21168ef-aeeb-45a0-bb98-27c576008560)

![WhatsApp Image 2025-08-09 at 06 41 13_781bbb31](https://github.com/user-attachments/assets/d9302b38-21f4-49eb-9a20-95810339d8bb)


STEPS OF PROJECT
Step 1:   Gather Components


Step 2:   Circuit Connections
        Sound Sensor (KY-038):   
        VCC → Arduino 5V
        GND → Arduino GND
        OUT → Arduino A0 (Analog Input)
        Relay/Transistor Setup:
        Relay IN → Arduino D9 (or Transistor Base via 1kΩ resistor)
        Relay VCC → Arduino 5V
        Relay GND → Arduino GND
        Vibration Motor:
        Motor (+) → Relay NO (Normally Open)
        Motor (-) → GND
        Power:
        Connect 9V Battery to Arduino Vin (or use USB).


Step 3: Upload Arduino Code
// Pin connections
const int soundSensorPin = 2;  // Digital output from sound sensor
const int relayPin = 8;        // Relay module input pin (Active LOW)

unsigned long relayOnTime = 0; // To store the time when relay turned ON
bool relayState = false;       // Current state of relay

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay OFF initially (Active LOW)
  Serial.begin(9600);           // Start serial monitor
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin);
  Serial.println(soundDetected); // Show sound detection value in Serial Monitor

  // If sound is detected and relay is currently OFF
  if (soundDetected == HIGH && !relayState) {
    relayState = true;
    relayOnTime = millis();         // Store the time relay turned ON
    digitalWrite(relayPin, LOW);    // Turn relay ON (Active LOW)
  }

  // If relay is ON, check if 15 seconds have passed
  if (relayState && (millis() - relayOnTime >= 15000)) {
    relayState = false;
    digitalWrite(relayPin, HIGH);   // Turn relay OFF (Active LOW)
  }
}
Step 4: Test & Calibrate


Step 5: Assemble in Pillow


Embed Components:
Place sound sensor near the pillow’s edge (to detect snoring).
Secure motor inside the pillow (near the sleeper’s head).
Hide Arduino + battery in a small fabric pouch attached to the pillow.

Safety Check:
Ensure no loose wires or sharp edges.

Step 6: Power & Use
Plug in the battery/USB.
Place the pillow on the bed; it will vibrate only when snoring is detected.



### Project Demo
# Video
https://drive.google.com/file/d/1uahKLDbdLc94K9cteL4oYeB1gAohPYw5/view?usp=drivesdk

Snoring ruins sleep—for you and your partner. But what if your pillow could gently nudge you to stop? Today, we’ll build an Arduino-powered anti-snoring pillow that detects snoring and vibrates to help you

# Additional Demos
https://drive.google.com/file/d/1M4geye88NxB5rOOnY2HsMI9-1DzSlR8A/view?usp=drivesdk

## Team Contributions
- ALAN BABU N: HAEDWARE CONTRIBUTION
- AMINA SALI : SOFTWARE CONTRIBUTION
  
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--25-25?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)



