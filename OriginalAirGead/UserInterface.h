#ifndef UserInterface_desktop_CS210_h
#define UserInterface_desktop_CS210_h

//header file containing the functions the user interacts with.
class UserInterface {
public:
	void WelcomeMessage();
	void UserMenu();
	void UserVerification(int t_i);
	void RunInterestCalc();
	AirGead bank;
	int i;
};

#endif