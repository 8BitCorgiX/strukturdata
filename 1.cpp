#include<iostream>
using namespace std;
#include <vector>
#include <SFML/Graphics.hpp>

struct node
{
	int data;
	node *next;
	node *prev;
};

class DoubleLinkedList
{
private:
	node * head, *tail;
	int idx;
public:
	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
		idx = 0;
	}
	void createNode(int value)
	{
		node *temp = new node;
		temp->data = value;
		if (head == tail && head == NULL)
		{
			head = temp;
			tail = temp;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			head->prev = tail;
			tail->next = head;
		}
		idx++;
	}
	void display()
	{
		node *temp = new node;
		temp = head;

		for (int i = 0; i<idx; i++)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	void reversedisplay()
	{
		cout << "Reverse List: ";
		node *p1, *p2;
		p1 = head;
		p2 = p1->next;
		p1->next = NULL;
		p1->prev = p2;
		while (p2 != head)
		{
			p2->prev = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p2->prev;
		}
		tail = head;
		head = p1;
		display();
	}
	void sort(int pick)
	{
		bool swap;
		node *ptr, *lptr = NULL;
		do
		{
			ptr = head;
			swap = false;
			while (lptr != ptr->next)
			{
				char temp;
				if (ptr->data > ptr->next->data && pick == 1)
				{
					swap = true;
					temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
				}
				else if (ptr->data < ptr->next->data && pick == 2)
				{
					swap = true;
					temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
				}
				ptr = ptr->next;
			}
			lptr = ptr;
		} while (swap);
	}
	int getCoor(int find)
	{
		node *temp = new node;
		temp = head;
		for (int i = 0; i < idx; i++)
		{
			int isi = temp->data;
			if (find == i)
			{
				return isi;
			}
			temp = temp->next;
		}
	}
	int getIdxX(int find) {
		node *temp = new node;
		temp = head;
		for (int i = 0; i < idx; i++)
		{
			if (find == temp->data)
			{
				return i;
			}
			temp = temp->next;
		}
	}
	int getIdxY(int find) {
		node *temp = new node;
		temp = head;
		for (int i = 0; i < idx; i++)
		{
			if (find == temp->data)
			{
				return i;
			}
			temp = temp->next;
		}
	}
};
class Player
{
private:
	int score;
	int status;
public:
	Player()
	{
		score = 0;
		status = 0;
	}
	void setscore(int s)
	{
		score = s;
	}
	int getscore()
	{
		return score;
	}
	void setstatus(int s)
	{
		status = s;
	}
};

class Soldier
{
protected:
	int x, y;
	bool alive;
	int point;
public:
	Soldier()
	{}
	Soldier(int xx, int yy)
	{
		x = xx;
		y = yy;
		alive = true;
		point = 0;
	}
	void setstatus(bool stat)
	{
		alive = stat;
	}
	void setcurrentpos(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
	int getcurrentx()
	{
		return x;
	}
	int getcurrenty()
	{
		return y;
	}
	void setPoint(int pointt) {
		point = pointt;
	}
	int getpoint()
	{
		return point;
	}
	bool isAlive()
	{
		if (alive == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class King : public Soldier
{
protected:

public:
	King()
	{}
	King(int xx, int yy)
	{
		x = xx;
		y = yy;
		alive = true;
		point = 8;
	}
};

class Rook : public Soldier
{
protected:

public:
	Rook()
	{}
	Rook(int xx, int yy)
	{
		x = xx;
		y = yy;
		alive = true;
		point = 4;
	}
};

class Bishop : public Soldier
{
public:
	Bishop()
	{}
	Bishop(int xx, int yy)
	{
		x = xx;
		y = yy;
		alive = true;
		point = 4;
	}
};

class Pawn : public Soldier
{
protected:
	bool promotion;
public:
	Pawn()
	{}
	Pawn(int xx, int yy)
	{
		x = xx;
		y = yy;
		alive = true;
		point = 1;
	}
};

int main()
{
	//map coordinate list
	DoubleLinkedList mapcoorX, mapcoorY;
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	float count = 180.00;//180
	
	//respawnmerah
	mapcoorX.createNode(28); mapcoorY.createNode(672); //idx 0
	mapcoorX.createNode(193); mapcoorY.createNode(672); //idx 1
	mapcoorX.createNode(361); mapcoorY.createNode(672); //idx 2

														//4
	mapcoorX.createNode(28); mapcoorY.createNode(541); //idx 3
	mapcoorX.createNode(193); mapcoorY.createNode(541); //idx 4
	mapcoorX.createNode(361); mapcoorY.createNode(541); //idx 5

														//3
	mapcoorX.createNode(28); mapcoorY.createNode(410); //idx 6
	mapcoorX.createNode(193); mapcoorY.createNode(410); //idx 7
	mapcoorX.createNode(361); mapcoorY.createNode(410); //idx 8

														//2
	mapcoorX.createNode(28); mapcoorY.createNode(279); //idx 9
	mapcoorX.createNode(193); mapcoorY.createNode(279); //idx 10
	mapcoorX.createNode(361); mapcoorY.createNode(279); //idx 11

														//1
	mapcoorX.createNode(28); mapcoorY.createNode(148); //idx 12
	mapcoorX.createNode(193); mapcoorY.createNode(148); //idx 13
	mapcoorX.createNode(361); mapcoorY.createNode(148); //idx 14

	//respawnbiru
	mapcoorX.createNode(28); mapcoorY.createNode(17); //idx 15
	mapcoorX.createNode(193); mapcoorY.createNode(17); //idx 16
	mapcoorX.createNode(361); mapcoorY.createNode(17); //idx 17


													   //object chess piece;
	King kingred, kingblue;
	Rook rookred, rookblue;
	Bishop bishopred, bishopblue;
	Pawn pawnred, pawnblue;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	sf::Texture back;
	if (!back.loadFromFile("asset/map.jpg"))
	{

	}
	sf::Sprite background(back);
	sf::Vector2f targetSize(500.0f, 800.0f);
	background.setScale(
		targetSize.x / background.getLocalBounds().width,
		targetSize.y / background.getLocalBounds().height);


	//menteribiru
	sf::Texture mb;
	if (!mb.loadFromFile("asset/mentri-biru.jpg"))
	{

	}
	sf::Sprite menteribiru(mb);
	sf::Vector2f mb1(110.f, 110.f);
	menteribiru.setScale(
		mb1.x / menteribiru.getLocalBounds().height,
		mb1.y / menteribiru.getLocalBounds().height);



	//rajabiru
	sf::Texture rb;
	if (!rb.loadFromFile("asset/raja-biru.jpg"))
	{

	}
	sf::Sprite rajabiru(rb);
	sf::Vector2f rb1(110.f, 110.f);
	rajabiru.setScale(
		rb1.x / rajabiru.getLocalBounds().height,
		rb1.y / rajabiru.getLocalBounds().height);



	//bentengbiru
	sf::Texture bb;
	if (!bb.loadFromFile("asset/benteng-biru.jpg"))
	{

	}
	sf::Sprite bentengbiru(bb);
	sf::Vector2f bb1(110.f, 110.f);
	bentengbiru.setScale(
		bb1.x / bentengbiru.getLocalBounds().height,
		bb1.y / bentengbiru.getLocalBounds().height);



	//pionbiru
	sf::Texture pb;
	if (!pb.loadFromFile("asset/pion-biru.jpg"))
	{

	}
	sf::Sprite pionbiru(pb);
	sf::Vector2f pb1(110.f, 110.f);
	pionbiru.setScale(
		pb1.x / pionbiru.getLocalBounds().height,
		pb1.y / pionbiru.getLocalBounds().height);


	//starting point biru
	menteribiru.setPosition(sf::Vector2f(28, 148));
	rajabiru.setPosition(sf::Vector2f(193, 148));
	bentengbiru.setPosition(sf::Vector2f(361, 148));
	pionbiru.setPosition(sf::Vector2f(193, 279));
	bishopblue.setcurrentpos(28, 148);
	kingblue.setcurrentpos(193, 148);
	rookblue.setcurrentpos(361, 148);
	pawnblue.setcurrentpos(193, 279);
	pawnblue.setPoint(1);
	kingblue.setPoint(8);
	bishopblue.setPoint(4);
	rookblue.setPoint(4);



	//menterimerah
	sf::Texture mm;
	if (!mm.loadFromFile("asset/mentri-merah.jpg"))
	{

	}
	sf::Sprite menterimerah(mm);
	sf::Vector2f mm2(110.f, 110.f);
	menterimerah.setScale(
		mm2.x / menterimerah.getLocalBounds().height,
		mm2.y / menterimerah.getLocalBounds().height);



	//rajamerah
	sf::Texture rm;
	if (!rm.loadFromFile("asset/raja-merah.jpg"))
	{

	}
	sf::Sprite rajamerah(rm);
	sf::Vector2f rm2(110.f, 110.f);
	rajamerah.setScale(
		rm2.x / rajamerah.getLocalBounds().height,
		rm2.y / rajamerah.getLocalBounds().height);



	//bentengmerah
	sf::Texture bm;
	if (!bm.loadFromFile("asset/benteng-merah.jpg"))
	{

	}
	sf::Sprite bentengmerah(bm);
	sf::Vector2f bm2(110.f, 110.f);
	bentengmerah.setScale(
		bm2.x / bentengmerah.getLocalBounds().height,
		bm2.y / bentengmerah.getLocalBounds().height);



	//pionmerah
	sf::Texture pm;
	if (!pm.loadFromFile("asset/pion-merah.jpg"))
	{

	}
	sf::Sprite pionmerah(pm);
	sf::Vector2f pm2(110.f, 110.f);
	pionmerah.setScale(
		pm2.x / pionmerah.getLocalBounds().height,
		pm2.y / pionmerah.getLocalBounds().height);

	//starting point merah
	bentengmerah.setPosition(sf::Vector2f(28, 541));
	rajamerah.setPosition(sf::Vector2f(193, 541));
	menterimerah.setPosition(sf::Vector2f(361, 541));
	pionmerah.setPosition(sf::Vector2f(193, 410));
	bishopred.setcurrentpos(28, 541);
	kingred.setcurrentpos(193, 541);
	rookred.setcurrentpos(361, 541);
	pawnred.setcurrentpos(193, 410);
	pawnred.setPoint(1);
	kingred.setPoint(8);
	rookred.setPoint(4);
	bishopred.setPoint(4);


	int stat1 = 0;
	int stat2 = 0;
	int turn = 1;
	bool alreadyExecute = false;
	Player p1, p2;

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text textScore1, textScore2;
	textScore1.setFont(font);
	textScore1.setCharacterSize(30);
	textScore1.setPosition(680, 0);
	textScore1.setFillColor(sf::Color::White);
	int skor = p1.getscore();
	textScore1.setString(to_string(skor));

	textScore2.setFont(font);
	textScore2.setCharacterSize(30);
	textScore2.setPosition(780, 0);
	textScore2.setFillColor(sf::Color::White);
	skor = p2.getscore();
	textScore2.setString(to_string(skor));

	sf::Text textTurn,turnDetail;
	textTurn.setFont(font);
	textTurn.setCharacterSize(30);
	textTurn.setPosition(800, 300);
	textTurn.setFillColor(sf::Color::White);
	turnDetail.setFont(font);
	turnDetail.setCharacterSize(30);
	turnDetail.setPosition(650, 300);
	turnDetail.setFillColor(sf::Color::White);



	while (window.isOpen())
	{
		sf::Event event;
		//hitung waktu
		elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() <= count)
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					stat1 = 1;
					stat2 = 1;
					alreadyExecute = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					stat1 = 2;
					stat2 = 2;
					alreadyExecute = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
				{
					stat1 = 3;
					stat2 = 3;
					alreadyExecute = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
				{
					stat1 = 4;
					stat2 = 4;
					alreadyExecute = false;
				}
				if (event.type == sf::Event::KeyReleased)
				{
					if (!alreadyExecute)
					{
						if (event.key.code == sf::Keyboard::Numpad8)
						{
							if (stat1 == 2 && turn == 1)
							{
								int x = bentengbiru.getPosition().x;
								int y = bentengbiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148)
								{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									bentengbiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									if (rookblue.getcurrentx() == kingblue.getcurrentx() && rookblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnblue.getcurrentx() && rookblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopblue.getcurrentx() && rookblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (rookblue.getcurrentx() == kingred.getcurrentx() && rookblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnred.getcurrentx() && rookblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == rookred.getcurrentx() && rookblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopred.getcurrentx() && rookblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
									/*rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									if (kingblue.getcurrentx() <= rookblue.getcurrentx() && kingblue.getcurrenty() > rookblue.getcurrenty())
									{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									bentengbiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									turn = 2;
									}
									else if (kingblue.getcurrentx() < rookblue.getcurrentx() && kingblue.getcurrenty() >= rookblue.getcurrenty())
									{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									bentengbiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									turn = 2;
									}
									else
									{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									}*/
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajabiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
									/*kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									if (kingblue.getcurrentx() <= rookblue.getcurrentx() && kingblue.getcurrenty() > rookblue.getcurrenty())
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajabiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									turn = 2;
									}
									else if (kingblue.getcurrentx() < rookblue.getcurrentx() && kingblue.getcurrenty() >= rookblue.getcurrenty())
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajabiru.setPosition(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									turn = 2;
									}
									else
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									}*/
								}
							}
							//p2
							else if (stat2 == 1 && turn == 2)
							{
								int x = pionmerah.getPosition().x;
								int y = pionmerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148)
								{
									pawnred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									pionmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (pawnred.getcurrentx() == rookred.getcurrentx() && pawnred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (pawnred.getcurrentx() == kingred.getcurrentx() && pawnred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (pawnred.getcurrentx() == bishopred.getcurrentx() && pawnred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (pawnred.getcurrentx() == kingblue.getcurrentx() && pawnred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (pawnred.getcurrentx() == pawnblue.getcurrentx() && pawnred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (pawnred.getcurrentx() == rookblue.getcurrentx() && pawnred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (pawnred.getcurrentx() == bishopblue.getcurrentx() && pawnred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 2 && turn == 2)
							{
								int x = bentengmerah.getPosition().x;
								int y = bentengmerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148)
								{
									rookred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;
									if (rookred.getcurrentx() == pawnred.getcurrentx() && rookred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (rookred.getcurrentx() == kingred.getcurrentx() && rookred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopred.getcurrentx() && rookred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (rookred.getcurrentx() == kingblue.getcurrentx() && rookred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == pawnblue.getcurrentx() && rookred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == rookblue.getcurrentx() && rookred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopblue.getcurrentx() && rookred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad2)
						{
							if (stat1 == 1 && turn == 1)
							{
								int x = pionbiru.getPosition().x;
								int y = pionbiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541)
								{
									pawnblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									pionbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (pawnblue.getcurrentx() == rookblue.getcurrentx() && pawnblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (pawnblue.getcurrentx() == kingblue.getcurrentx() && pawnblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (pawnblue.getcurrentx() == bishopblue.getcurrentx() && pawnblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (pawnblue.getcurrentx() == kingred.getcurrentx() && pawnblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (pawnblue.getcurrentx() == pawnred.getcurrentx() && pawnblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										cout << pawnred.getpoint() << " " << p1.getscore() << endl;
										pawnred.setstatus(true);
									}
									else if (pawnblue.getcurrentx() == rookred.getcurrentx() && pawnblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (pawnblue.getcurrentx() == bishopred.getcurrentx() && pawnblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 2 && turn == 1)
							{
								int x = bentengbiru.getPosition().x;
								int y = bentengbiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541)
								{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (rookblue.getcurrentx() == kingblue.getcurrentx() && rookblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnblue.getcurrentx() && rookblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopblue.getcurrentx() && rookblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (rookblue.getcurrentx() == kingred.getcurrentx() && rookblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnred.getcurrentx() && rookblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == rookred.getcurrentx() && rookblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopred.getcurrentx() && rookblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 2 && turn == 2)
							{
								int x = bentengmerah.getPosition().x;
								int y = bentengmerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541)
								{
									rookred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (rookred.getcurrentx() == pawnred.getcurrentx() && rookred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (rookred.getcurrentx() == kingred.getcurrentx() && rookred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopred.getcurrentx() && rookred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (rookred.getcurrentx() == kingblue.getcurrentx() && rookred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == pawnblue.getcurrentx() && rookred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == rookblue.getcurrentx() && rookred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopblue.getcurrentx() && rookred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad4)
						{
							if (stat1 == 2 && turn == 1)
							{
								int x = bentengbiru.getPosition().x;
								int y = bentengbiru.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									if (rookblue.getcurrentx() == kingblue.getcurrentx() && rookblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnblue.getcurrentx() && rookblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopblue.getcurrentx() && rookblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (rookblue.getcurrentx() == kingred.getcurrentx() && rookblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnred.getcurrentx() && rookblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == rookred.getcurrentx() && rookblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopred.getcurrentx() && rookblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 2 && turn == 2)
							{
								int x = bentengmerah.getPosition().x;
								int y = bentengmerah.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									rookred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 1;

									if (rookred.getcurrentx() == pawnred.getcurrentx() && rookred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (rookred.getcurrentx() == kingred.getcurrentx() && rookred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopred.getcurrentx() && rookred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (rookred.getcurrentx() == kingblue.getcurrentx() && rookred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == pawnblue.getcurrentx() && rookred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == rookblue.getcurrentx() && rookred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopblue.getcurrentx() && rookred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad6)
						{
							if (stat1 == 2 && turn == 1)
							{
								int x = bentengbiru.getPosition().x;
								int y = bentengbiru.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									rookblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									if (rookblue.getcurrentx() == kingblue.getcurrentx() && rookblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnblue.getcurrentx() && rookblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopblue.getcurrentx() && rookblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (rookblue.getcurrentx() == kingred.getcurrentx() && rookblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == pawnred.getcurrentx() && rookblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == rookred.getcurrentx() && rookblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (rookblue.getcurrentx() == bishopred.getcurrentx() && rookblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
									/*kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									if (kingblue.getcurrentx() <= rookblue.getcurrentx() &&kingblue.getcurrenty() > rookblue.getcurrenty())
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 2;
									}
									else if (kingblue.getcurrentx() < rookblue.getcurrentx() && kingblue.getcurrenty() >= rookblue.getcurrenty())
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 2;
									}
									else
									{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									}*/
								}
							}
							//p2
							else if (stat2 == 2 && turn == 2)
							{
								int x = bentengmerah.getPosition().x;
								int y = bentengmerah.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									rookred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 1;

									if (rookred.getcurrentx() == pawnred.getcurrentx() && rookred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (rookred.getcurrentx() == kingred.getcurrentx() && rookred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopred.getcurrentx() && rookred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (rookred.getcurrentx() == kingblue.getcurrentx() && rookred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == pawnblue.getcurrentx() && rookred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (rookred.getcurrentx() == rookblue.getcurrentx() && rookred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookred.setstatus(true);
									}
									else if (rookred.getcurrentx() == bishopblue.getcurrentx() && rookred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad7)
						{
							if (stat1 == 3 && turn == 1)
							{
								int x = menteribiru.getPosition().x;
								int y = menteribiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									bishopblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									if (bishopblue.getcurrentx() == kingblue.getcurrentx() && bishopblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnblue.getcurrentx() && bishopblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookblue.getcurrentx() && bishopblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}


									if (bishopblue.getcurrentx() == kingred.getcurrentx() && bishopblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnred.getcurrentx() && bishopblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookred.getcurrentx() && bishopblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == bishopred.getcurrentx() && bishopblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 3 && turn == 2)
							{
								int x = menterimerah.getPosition().x;
								int y = menterimerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									bishopred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (bishopred.getcurrentx() == rookred.getcurrentx() && bishopred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == kingred.getcurrentx() && bishopred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnred.getcurrentx() && bishopred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									if (bishopred.getcurrentx() == kingblue.getcurrentx() && bishopred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnblue.getcurrentx() && bishopred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == rookblue.getcurrentx() && bishopred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == bishopblue.getcurrentx() && bishopred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad9)
						{
							if (stat1 == 3 && turn == 1)
							{
								int x = menteribiru.getPosition().x;
								int y = menteribiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									bishopblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									if (bishopblue.getcurrentx() == kingblue.getcurrentx() && bishopblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnblue.getcurrentx() && bishopblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookblue.getcurrentx() && bishopblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}


									if (bishopblue.getcurrentx() == kingred.getcurrentx() && bishopblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnred.getcurrentx() && bishopblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookred.getcurrentx() && bishopblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == bishopred.getcurrentx() && bishopblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 3 && turn == 2)
							{
								int x = menterimerah.getPosition().x;
								int y = menterimerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									bishopred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (bishopred.getcurrentx() == rookred.getcurrentx() && bishopred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == kingred.getcurrentx() && bishopred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnred.getcurrentx() && bishopred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}

									if (bishopred.getcurrentx() == kingblue.getcurrentx() && bishopred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnblue.getcurrentx() && bishopred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == rookblue.getcurrentx() && bishopred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == bishopblue.getcurrentx() && bishopred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3) >= 148 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad1)
						{
							if (stat1 == 3 && turn == 1)
							{
								int x = menteribiru.getPosition().x;
								int y = menteribiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									bishopblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (bishopblue.getcurrentx() == kingblue.getcurrentx() && bishopblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnblue.getcurrentx() && bishopblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookblue.getcurrentx() && bishopblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}


									if (bishopblue.getcurrentx() == kingred.getcurrentx() && bishopblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnred.getcurrentx() && bishopblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookred.getcurrentx() && bishopblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == bishopred.getcurrentx() && bishopblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 3 && turn == 2)
							{
								int x = menterimerah.getPosition().x;
								int y = menterimerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									bishopred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (bishopred.getcurrentx() == rookred.getcurrentx() && bishopred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == kingred.getcurrentx() && bishopred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnred.getcurrentx() && bishopred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}

									if (bishopred.getcurrentx() == kingblue.getcurrentx() && bishopred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnblue.getcurrentx() && bishopred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == rookblue.getcurrentx() && bishopred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == bishopblue.getcurrentx() && bishopred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1) <= 361)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
						if (event.key.code == sf::Keyboard::Numpad3)
						{
							if (stat1 == 3 && turn == 1)
							{
								int x = menteribiru.getPosition().x;
								int y = menteribiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									bishopblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (bishopblue.getcurrentx() == kingblue.getcurrentx() && bishopblue.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										kingblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnblue.getcurrentx() && bishopblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookblue.getcurrentx() && bishopblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}


									if (bishopblue.getcurrentx() == kingred.getcurrentx() && bishopblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == pawnred.getcurrentx() && bishopblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == rookred.getcurrentx() && bishopblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										pawnred.setstatus(true);
									}
									else if (bishopblue.getcurrentx() == bishopred.getcurrentx() && bishopblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							else if (stat1 == 4 && turn == 1)
							{
								int x = rajabiru.getPosition().x;
								int y = rajabiru.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingblue.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									if (kingblue.getcurrentx() == rookblue.getcurrentx() && kingblue.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										rookblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnblue.getcurrentx() && kingblue.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										pawnblue.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopblue.getcurrentx() && kingblue.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() - 10);
										bishopblue.setstatus(true);
									}


									if (kingblue.getcurrentx() == kingred.getcurrentx() && kingblue.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + kingred.getpoint());
										kingred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == pawnred.getcurrentx() && kingblue.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + pawnred.getpoint());
										pawnred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == rookred.getcurrentx() && kingblue.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + rookred.getpoint());
										rookred.setstatus(true);
									}
									else if (kingblue.getcurrentx() == bishopred.getcurrentx() && kingblue.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p1.setscore(p1.getscore() + bishopred.getpoint());
										bishopred.setstatus(true);
									}
									turn = 2;
								}
							}
							//p2
							else if (stat2 == 3 && turn == 2)
							{
								int x = menterimerah.getPosition().x;
								int y = menterimerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									bishopred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (bishopred.getcurrentx() == rookred.getcurrentx() && bishopred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == kingred.getcurrentx() && bishopred.getcurrenty() == kingred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										kingred.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnred.getcurrentx() && bishopred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}

									if (bishopred.getcurrentx() == kingblue.getcurrentx() && bishopred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == pawnblue.getcurrentx() && bishopred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == rookblue.getcurrentx() && bishopred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (bishopred.getcurrentx() == bishopblue.getcurrentx() && bishopred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							else if (stat2 == 4 && turn == 2)
							{
								int x = rajamerah.getPosition().x;
								int y = rajamerah.getPosition().y;
								if (mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3) <= 541 && mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1) > 28)
								{
									kingred.setcurrentpos(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3));
									rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
									turn = 1;

									if (kingred.getcurrentx() == rookred.getcurrentx() && kingred.getcurrenty() == rookred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										rookred.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnred.getcurrentx() && kingred.getcurrenty() == pawnred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										pawnred.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopred.getcurrentx() && kingred.getcurrenty() == bishopred.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() - 10);
										bishopred.setstatus(true);
									}

									if (kingred.getcurrentx() == kingblue.getcurrentx() && kingred.getcurrenty() == kingblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + kingblue.getpoint());
										kingblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == pawnblue.getcurrentx() && kingred.getcurrenty() == pawnblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + pawnblue.getpoint());
										pawnblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == rookblue.getcurrentx() && kingred.getcurrenty() == rookblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + rookblue.getpoint());
										rookblue.setstatus(true);
									}
									else if (kingred.getcurrentx() == bishopblue.getcurrentx() && kingred.getcurrenty() == bishopblue.getcurrenty() && turn == 1)
									{
										p2.setscore(p2.getscore() + bishopblue.getpoint());
										bishopblue.setstatus(true);
									}
								}
							}
							alreadyExecute = true;
						}
					}
				}
				skor = p1.getscore();
				textScore1.setString(to_string(skor));
				skor = p2.getscore();
				textScore2.setString(to_string(skor));
				textTurn.setString(to_string(turn));
				turnDetail.setString("Turn:");
				window.clear();

				window.draw(background);
				if (!pawnblue.isAlive())
				{
					window.draw(pionbiru);
				}
				else
				{
					pawnblue.setcurrentpos(pawnblue.getcurrentx(), 17);
					pionbiru.setPosition(sf::Vector2f(pawnblue.getcurrentx(), pawnblue.getcurrenty()));
					pawnblue.setstatus(false);
				}

				if (!bishopblue.isAlive())
				{
					window.draw(menteribiru);
				}
				else
				{
					bishopblue.setcurrentpos(bishopblue.getcurrentx(), 17);
					menteribiru.setPosition(sf::Vector2f(bishopblue.getcurrentx(), bishopblue.getcurrenty()));
					bishopblue.setstatus(false);
				}
				if (!kingblue.isAlive())
				{
					window.draw(rajabiru);
				}
				else {
					kingblue.setcurrentpos(kingblue.getcurrentx(), 17);
					rajabiru.setPosition(sf::Vector2f(kingblue.getcurrentx(), kingblue.getcurrenty()));
					kingblue.setstatus(false);
				}
				if (!rookblue.isAlive())
				{
					window.draw(bentengbiru);
				}
				else {
					rookblue.setcurrentpos(rookblue.getcurrentx(), 17);
					bentengbiru.setPosition(sf::Vector2f(rookblue.getcurrentx(), rookblue.getcurrenty()));
					rookblue.setstatus(false);
				}
				if (!pawnred.isAlive())
				{
					window.draw(pionmerah);
				}
				else {
					pawnred.setcurrentpos(pawnred.getcurrentx(), 672);
					pionmerah.setPosition(sf::Vector2f(pawnred.getcurrentx(), pawnred.getcurrenty()));
					pawnred.setstatus(false);
				}
				if (!bishopred.isAlive())
				{
					window.draw(menterimerah);
				}
				else {
					bishopred.setcurrentpos(bishopred.getcurrentx(), 672);
					menterimerah.setPosition(sf::Vector2f(bishopred.getcurrentx(), bishopred.getcurrenty()));
					bishopred.setstatus(false);
				}
				if (!rookred.isAlive())
				{
					window.draw(bentengmerah);
				}
				else {
					rookred.setcurrentpos(rookred.getcurrentx(), 672);
					bentengmerah.setPosition(sf::Vector2f(rookred.getcurrentx(), rookred.getcurrenty()));
					rookred.setstatus(false);
				}
				if (!kingred.isAlive())
				{
					window.draw(rajamerah);
				}
				else {
					kingred.setcurrentpos(kingred.getcurrentx(), 672);
					rajamerah.setPosition(sf::Vector2f(kingred.getcurrentx(), kingred.getcurrenty()));
					kingred.setstatus(false);
				}
			window.draw(textScore1);
			window.draw(textScore2);
			window.draw(textTurn);
			window.draw(turnDetail);
			window.display();
		}

	}
	else
	{
		cout << "Waktu habis\n";
		if (p1.getscore() > p2.getscore())
		{
			cout << "Blue Team Win!"<<endl;
		}
		else if (p1.getscore() < p2.getscore())
		{
			cout << "Red Team Win!" << endl;
		}
		else
		{
			cout << "Draw!"<<endl;
		}
		/*sf::Text exit;
		font.loadFromFile("arial.ttf");
		exit.setFont(font);
		exit.setString("Done");
		exit.setPosition(350, 300);
		window.clear(sf::Color::White);
		window.draw(exit);*/
		window.close();
	}

	}
	return 0;
}