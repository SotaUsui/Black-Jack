#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Card{
    public:
        int value;
        string name;
        string suit;
};

class Deck{
    public:
        vector<Card> cards;
        vector<Card> suit;
        Card card;
        void MakeDeck(){
            for(int i=0; i<4; i++){
                for(int j=1; j<14; j++){
                    if(i==0){
                        card.suit = "Spades";
                    }
                    if(i==1){
                        card.suit = "Clubs";
                    }
                    if(i==2){
                        card.suit = "Hearts";
                    }
                    if(i==3){
                        card.suit ="Diamonds";
                    }

                    if(j==1){
                        card.name = "A";
                        card.value = 11;
                        cards.push_back(card);
                    }
                    else if(j==2){
                        card.name = "2";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==3){
                        card.name = "3";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==4){
                        card.name = "4";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==5){
                        card.name = "5";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==6){
                        card.name = "6";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==7){
                        card.name = "7";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==8){
                        card.name = "8";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==9){
                        card.name = "9";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==10){
                        card.name = "10";
                        card.value = j;
                        cards.push_back(card);
                    }
                    else if(j==11){
                        card.name = "J";
                        card.value = 10;
                        cards.push_back(card);
                    }
                    else if(j==12){
                        card.name = "Q";
                        card.value = 10;
                        cards.push_back(card);
                    }
                    else if(j==13){
                        card.name = "K";
                        card.value = 10;
                        cards.push_back(card);
                    }
                }
            }
            int random;
            srand(time(0));
            random = rand()%10;
            for(int i=0; i<random; i++){
                random_shuffle(cards.begin(),cards.end());
            }
        }
};


int main(){
    cout << "Welcom to Blackjack"<< endl;
    
    Deck deck;
    deck.MakeDeck(); 

    vector<Card> player;
    vector<Card> dealer;

    int player_score =0;
    int player_score_1 =0;
    int player_score_2 =0;
    int dealer_score =0;
    bool turn = true;

    //deal out cards
    player.push_back(deck.cards[0]);
    player_score_1 += deck.cards[0].value;
    deck.cards.erase(deck.cards.begin());
    
    dealer.push_back(deck.cards[0]);
    dealer_score += deck.cards[0].value;
    deck.cards.erase(deck.cards.begin());

    player.push_back(deck.cards[0]);
    player_score_1 += deck.cards[0].value;
    deck.cards.erase(deck.cards.begin());

    dealer.push_back(deck.cards[0]);
    dealer_score += deck.cards[0].value;
    deck.cards.erase(deck.cards.begin());

    cout << "Your hand is ";

    for(int i=0; i<player.size(); i++){
        cout <<"<"<<player[i].suit << " "<<player[i].name <<"> " ;
    }
    cout << endl;

    for(int i=0; i<player.size(); i++){
        if(player[i].name == "A"){
            player[i].value = 1;
        }
        player_score_2 += player[i].value;
    }

    if(player_score_1 == 21){
        cout << "BlackJack!!!" <<endl;
        turn = false;
        player_score = player_score_1;
    }



    cout << "One of the delaer's hand is <" << dealer[0].suit <<" " <<dealer[0].name<<">" <<endl;

    
    //player's turn
    while(turn == true){
        string x;
        cout << "stand or hit: ";
        cin >> x;
        if(x == "stand"){
            turn = false;
        }
        else if(x == "hit"){
            player.push_back(deck.cards[0]);
            if(deck.cards[0].name == "A"){
                player_score_1 += 11;
                player_score_2 += 1;
            }
            else{
                player_score_1 += deck.cards[0].value;
                player_score_2 += deck.cards[0].value;
            }

            deck.cards.erase(deck.cards.begin());

            cout << "Your hand is ";
            for(int i=0; i<player.size(); i++){
                cout <<"<"<<player[i].suit << " "<<player[i].name <<"> " ;
            }
        cout << endl;
        }

        else{
        }

        if(player_score_2 > 21){
            cout << "Your hand is over 21" << endl;
            turn = false;
        }
        else if (player_score_1 == 21){
            cout << "Your hand is 21!" << endl;
            turn = false;
        }
        else if (player_score_2 == 21){
            cout << "Your hand is 21!" << endl;
            turn = false;
        }
        

    }

    //delear's turn
    cout<< "Dealer's hand is ";
    for(int i=0; i<dealer.size(); i++){
        cout <<"<"<<dealer[i].suit << " "<<dealer[i].name <<"> " ;
    }
    cout << endl;

    while(dealer_score <17){
        cout << "Dealer draws a card"<< endl;
        dealer.push_back(deck.cards[0]);
        if(deck.cards[0].name == "A" && dealer_score >10){
            dealer[0].value = 1;
        }
        dealer_score += deck.cards[0].value;
        deck.cards.erase(deck.cards.begin());


        for (int i=0; i>2; i++){
            if (dealer_score > 21 && dealer[i].name == "A"){
                dealer_score = dealer_score -10;
            }
        }

        for(int i=0; i<dealer.size(); i++){
        cout <<"<"<<dealer[i].suit << " "<<dealer[i].name <<"> " ;
        }
    cout << endl;
    }

    //player_score
    if(player_score_1 == player_score_2){
        player_score = player_score_1;
    }
    else if(player_score_1 <= 21){
        player_score = player_score_1;
    }
    else{
        player_score = player_score_2;
    }


    // win or lose
    if(player_score > 21){
        cout << "You lose!" << endl;
    }
    else if(dealer_score > 21){
        cout << "You win!!"<< endl;
    }
    else if(player_score > dealer_score){
        cout << "You win!!" << endl;
    }
    else if(player_score < dealer_score){
        cout << "You lose!" << endl;
    }
    else{
        cout << "tie"<< endl;
    }

    return 0;
}
