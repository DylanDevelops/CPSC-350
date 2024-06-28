#include <iostream>

using namespace std;
int main() {
    int choice1, choice2, choice3, choice4, choice5;
    int karma = 50;

    cout << "Welcome to the Moral Dilemma Game!" << endl;

    // Question 1
    for(int i = 0; i < 10; i++) {
        cout << "\nQ1) You are at your best friend's wedding just an hour before the ceremony is to start. Earlier that day, you came across definitive proof that your best friend's spouse-to-be is having an affair with the best man/maid of honor, and you catch them sneaking out of a room together looking disheveled. If you tell your friend about the affair, their day will be ruined, but you don't want them to marry a cheater. What do you do?" << endl;
        cout << "   1) Tell your best friend; sure the day will be ruined, but better a day ruined than an entire life.\n   2) Say nothing; your job is to be supportive and participate in your friend's happiness.\nAnswer: ";
        cin >> choice1;

        bool answered = false;

        switch(choice1) {
            case 1:
                karma += 10;
                answered = true;
                break;
            
            case 2:
                karma -= 10;
                answered = true;
                break;
        }

        if(answered) {
            break;
        }
    }

    if(karma > 100) {
        karma = 100;
    } else if(karma < 0) {
        karma = 0;
    }

    // Question 2
    for(int i = 0; i < 10; i++) {
        cout << "\nQ2) You are an eyewitness to a crime: A man has robbed a bank, but instead of keeping the money for himself, he donates it to a poor orphanage that can now afford to feed, clothe, and care for its children. You know who committed the crime. If you go to the authorities with the information, there's a good chance the money will be returned to the bank, leaving a lot of kids in need. What do you do?" << endl;
        cout << "   1) Turn the robber in to the authorities; right is right.\n   2) Say nothing since the money went to what you deem a good cause.\nAnswer: ";
        cin >> choice1;

        bool answered = false;

        switch(choice1) {
            case 1:
                karma += 30;
                answered = true;
                break;
            
            case 2:
                karma += 10;
                answered = true;
                break;
        }

        if(answered) {
            break;
        }

        cout << "\nPlease choose either '1' or '2'\n" << endl;
    }

    if(karma > 100) {
        karma = 100;
    } else if(karma < 0) {
        karma = 0;
    }

    // Question 3
    for(int i = 0; i < 10; i++) {
        cout << "\nQ3) You've been on a cruise for two days when there's an accident that forces everyone on board to abandon ship. During the evacuation, one of the boats is damaged, leaving it with a hole that fills it with water. You figure that with 10 people in the boat, you can keep the boat afloat by having nine people scoop the filling water out by hand for 10 minutes while the 10th person rests. After that person's 10-minute rest, he or she will get back to work while another person rests, and so on. This should keep the boat from sinking long enough for a rescue team to find you as long as it happens within five hours. You're taking your first brake when you notice your best friend in a sound lifeboat with only nine people in it and he beckons you to swim over and join them so you won't have to keep bailing out water. If you leave the people in the sinking boat, they will only be able to stay afloat for two hours instead of five, decreasing their chance of being rescued, but securing yours. What do you do?" << endl;
        cout << "   1) Stay in your boat and hope that you are all rescued in five hours time, before the boat sinks and you all drown.\n   2) Jump ship and join your friend in his boat and hope that the others are rescued within two hours.\nAnswer: ";
        cin >> choice1;

        bool answered = false;

        switch(choice1) {
            case 1:
                karma += 50;
                answered = true;
                break;
            
            case 2:
                karma -= 40;
                answered = true;
                break;
        }

        if(answered) {
            break;
        }

        cout << "\nPlease choose either '1' or '2'\n" << endl;
    }

    if(karma > 100) {
        karma = 100;
    } else if(karma < 0) {
        karma = 0;
    }

    // Question 4
    for(int i = 0; i < 10; i++) {
        cout << "\nQ4) You have a job as network administrator for a company that also employs your best friend's husband. One day, your best friend's husband sends you a message asking you to release an email from quarantine. This requires you to open the email, at which point you discover that it's correspondence between this guy and his secret lover. After releasing the email, you find yourself in a pickle. Your instinct is to tell your best friend about his husband's infidelities, but divulging the contents of company emails is against company policy and you could lose your job. Once it becomes plain that your best friend found out about his cheating husband through a company email, all trails will inevitably lead to you as the leak. Do you tell him about the indiscretion?" << endl;
        cout << "   1) Yes; your loyalty to your best friend eclipses any company policy.\n    2) No; it sucks that your best friend has a cheating husband, but you can't risk losing your job. \nAnswer: ";
        cin >> choice1;

        bool answered = false;

        switch(choice1) {
            case 1:
                karma += 10;
                answered = true;
                break;
            
            case 2:
                karma += 0;
                answered = true;
                break;
        }

        if(answered) {
            break;
        }

        cout << "\nPlease choose either '1' or '2'\n" << endl;
    }

    if(karma > 100) {
        karma = 100;
    } else if(karma < 0) {
        karma = 0;
    }

    // Question 5
    for(int i = 0; i < 10; i++) {
        cout << "\nQ5) You're involved in a two-car crash on your way to work one morning in which you accidentally hit and kill a pedestrian. As you get out of the car, you are intercepted by a tearful woman who seems to think that she hit and killed the pedestrian. You're not sure why she thinks she hit the person, but she is convinced. There's only you, the woman, and the person you hit on the road; there are no witnesses. You know that whoever is deemed responsible will probably be sent to jail. What do you do?" << endl;
        cout << "   1) Confess your responsibility; you wouldn't be able to live with the guilt of an innocent person being in jail for a crime you committed.\n   2) Let the woman take the blame; the thought of being locked away from your life and family is too much to bear.\nAnswer: ";
        cin >> choice1;

        bool answered = false;

        switch(choice1) {
            case 1:
                karma += 60;
                answered = true;
                break;
            
            case 2:
                karma -= 70;
                answered = true;
                break;
        }

        if(answered) {
            break;
        }

        cout << "\nPlease choose either '1' or '2'\n" << endl;
    }

    if(karma > 100) {
        karma = 100;
    } else if(karma < 0) {
        karma = 0;
    }

    cout << "Final Karma Score: " << karma << "/100" << endl;

    if(karma <= 33) {
        cout << "Bad Karma Ending: Your journey has been marked by choices that often favored self-preservation at the expense of others. The consequences of your actions have left a trail of discord and sorrow, reflecting the darker path you've chosen." << endl;
    } else if(karma > 33 && karma < 67) {
        cout << "Neutral Karma Ending: Your path has been one of balance, walking the line between light and darkness. Your actions have sometimes helped, sometimes hindered, but always sought to find a middle ground, leaving a legacy of mixed outcomes." << endl;
    } else if(karma >= 67) {
        cout << "Good Karma Ending: Your choices have consistently reflected a commitment to the greater good. The positive impact of your actions has rippled through the lives of many, leaving a lasting legacy of hope and change." << endl;
    }

    return 0;
}