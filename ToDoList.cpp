#include <iostream>

// Created by Bogdan Zazhigin.
int main(void) {
	
	// Pre-configuration.
	std::cout << "\033[40m Pre-configuring..." << std::endl;
	bool end = false; char action = ' '; char nameSelecting = ' '; char statusSelecting = ' '; int points = 0; int lastPointsStatus = 0; int fullDone = 0; std::string notification = ""; bool stop = false;
	std::string name1 = "-", name2 = "-", name3 = "-", name4 = "-", name5 = "-", name6 = "-", name7 = "-", name8 = "-", status1 = "\033[31mFREEZED\033[0m\t", status2 = "\033[31mFREEZED\033[0m\t", status3 = "\033[31mFREEZED\033[0m\t", status4 = "\033[31mFREEZED\033[0m\t", status5 = "\033[31mFREEZED\033[0m\t", status6 = "\033[31mFREEZED\033[0m\t", status7 = "\033[31mFREEZED\033[0m\t", status8 = "\033[31mFREEZED\033[0m\t";
	system("clear");

	// Greeting.	
	std::cout << "Enter \'\033[1m?\033[0m\' (help) for see the list of commands.\n---\n";

	// MAIN CODE.
	while(end != true) {

		// Command enter.
		std::cout << "Action » \033[1m"; std::cin >> action; std::cout << "\033[0m" << std::endl;
		
		// Commands.
		switch(action) {

			// List of tasks.
            ListOfTasks:
			case 'L': case 'l':
				system("clear");
				std::cout << "┌\033[1;4mID│ Status      │ Name \n\033[0m";
				std::cout << "│ 1│ " + status1 + " │ " + name1 << std::endl;
				std::cout << "│ 2│ " + status2 + " │ " + name2 << std::endl;
				std::cout << "│ 3│ " + status3 + " │ " + name3 << std::endl;
				std::cout << "│ 4│ " + status4 + " │ " + name4 << std::endl;
				std::cout << "│ 5│ " + status5 + " │ " + name5 << std::endl;
				std::cout << "│ 6│ " + status6 + " │ " + name6 << std::endl;
				std::cout << "│ 7│ " + status7 + " │ " + name7 << std::endl;
				std::cout << "│ 8│ " + status8 + " │ " + name8 << std::endl;
				std::cout << "│─────────────────────────────┐\n│points: "; 
                if(points <= 0) std::cout << "Finish your first task to get point." << std::endl;
                if(points > 0) std::cout << points << std::endl;
				std::cout << "└─────────────────────────────┘\n" << notification << std::endl;
                notification = "";
				break;

			// Create / rename task.
			case 'G': case 'g':
				std::cin >> nameSelecting;                
				switch(nameSelecting) {
                    case '1':   if(status1 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name1); notification = "\033[1;4mName\033[0m for \033[1mfirst task\033[0m is \"" + name1 + "\".\n"; goto ListOfTasks; break;
                    case '2':   if(status2 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name2); notification = "\033[1;4mName\033[0m for \033[1msecond task\033[0m is \"" + name2 + "\".\n"; goto ListOfTasks; break;
					case '3':   if(status3 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name3); notification = "\033[1;4mName\033[0m for \033[1mthird task\033[0m is \"" + name3 + "\".\n"; goto ListOfTasks; break;
					case '4':   if(status4 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name4); notification = "\033[1;4mName\033[0m for \033[1mfourth task\033[0m is \"" + name4 + "\".\n"; goto ListOfTasks; break;
					case '5':   if(status5 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name5); notification = "\033[1;4mName\033[0m for \033[1mfifth task\033[0m is \"" + name5 + "\".\n"; goto ListOfTasks; break;
					case '6':   if(status6 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name6); notification = "\033[1;4mName\033[0m for \033[1msixth task\033[0m is \"" + name6 + "\".\n"; goto ListOfTasks; break;
					case '7':   if(status7 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name7); notification = "\033[1;4mName\033[0m for \033[1mseventh task\033[0m is \"" + name7 + "\".\n"; goto ListOfTasks; break;
					case '8':   if(status8 == "\033[1;93mDONE\033[0m\t") break; getline(std::cin, name8); notification = "\033[1;4mName\033[0m for \033[1meighth task\033[0m is \"" + name8 + "\".\n"; goto ListOfTasks; break;
					default:    notification = "\033[1;31mID is not valid!\033[0m\n"; goto ListOfTasks;
				} break;

			// Change status for task.
            case 'F': case 'f': 
				std::cin >> nameSelecting; switch(nameSelecting) {
                    case '1':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name1 == "-") {notification = "Status \"DONE\" can't be changed for basic name \"-\".\n"; goto ListOfTasks; break;} status1 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1mfirst task\033[0m is \"DONE\".\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status1 == "\033[1;93mDONE\033[0m\t") {notification = "Status \"DONE\" can't be rechanged.\n"; goto ListOfTasks; break;} status1 = "\033[34mIN PROGRESS\033[0m"; notification = "\033[1;4mStatus\033[0m for \033[1mfisrt task\033[0m is \"IN PROGRESS\".\n"; goto ListOfTasks; break;
					                case 'Y': case 'y': if(status1 == "\033[1;93mDONE\033[0m\t") {notification = "Status \"DONE\" can't be rechanged.\n"; goto ListOfTasks; break;} status1 = "\033[31mFREEZED\033[0m\t"; notification = "\033[1;4mStatus\033[0m for \033[1mfirst task\033[0m is \"FREEZED\"\n"; goto ListOfTasks; break;
					                default: notification = "\033[1;4;31mStatus\033[0;1;31m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '2':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name2 == "-") break; status2 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1msecond task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status2 == "\033[2;93mDONE\033[0m\t") break; status2 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status2 == "\033[2;93mDONE\033[0m\t") break; status2 = "\033[32mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[1;31m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '3':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name3 == "-") break; status3 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1mthird task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status3 == "\033[3;93mDONE\033[0m\t") break; status3 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status3 == "\033[3;93mDONE\033[0m\t") break; status3 = "\033[33mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[1;31m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '4':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name4 == "-") break; status4 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1mfourth task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status4 == "\033[4;93mDONE\033[0m\t") break; status4 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status4 == "\033[4;93mDONE\033[0m\t") break; status4 = "\033[34mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[4;34m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '5':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name5 == "-") break; status5 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1mfifth task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status5 == "\033[5;93mDONE\033[0m\t") break; status5 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status5 == "\033[5;93mDONE\033[0m\t") break; status5 = "\033[35mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[5;35m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '6':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name6 == "-") break; status6 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1msixth task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status6 == "\033[6;93mDONE\033[0m\t") break; status6 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status6 == "\033[6;93mDONE\033[0m\t") break; status6 = "\033[36mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[6;36m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '7':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name7 == "-") break; status7 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1mseventh task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status7 == "\033[7;93mDONE\033[0m\t") break; status7 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status7 == "\033[7;93mDONE\033[0m\t") break; status7 = "\033[37mFREEZED\033[0m\t"; break;
					                default: notification = "\n\033[7;37m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
                    case '8':   std::cin >> statusSelecting; switch(statusSelecting) {
                                    case 'R': case 'r': if(name8 == "-") break; status8 = "\033[1;93mDONE\033[0m\t"; points++; notification = "\033[1;4mStatus\033[0m for \033[1meighth task\033[0m is \"DONE\"\n"; goto ListOfTasks; break;
					                case 'T': case 't': if(status8 == "\033[8;93mDONE\033[0m\t") break; status8 = "\033[34mIN PROGRESS\033[0m"; break;
					                case 'Y': case 'y': if(status8 == "\033[8;93mDONE\033[0m\t") break; status8 = "\033[38mFREEZED\033[0m\t"; break;
					                default: notification = "\033[8;38m033[1;4mStatus033[0m is not valid!\033[0m\n"; goto ListOfTasks; break;
					            } break;
					default:    notification = "\033[1;31mID is not valid!\033[0m\n"; goto ListOfTasks;
            } break;

            // Clear tasks.	
            case 'C': case 'c' :
                status1 = "\033[31mFREEZED\033[0m\t", status2 = "\033[31mFREEZED\033[0m\t", status3 = "\033[31mFREEZED\033[0m\t", status4 = "\033[31mFREEZED\033[0m\t", status5 = "\033[31mFREEZED\033[0m\t", status6 = "\033[31mFREEZED\033[0m\t", status7 = "\033[31mFREEZED\033[0m\t", status8 = "\033[31mFREEZED\033[0m\t";
                name1 = '-'; name2 = '-'; name3 = '-'; name4 = '-'; name5 = '-'; name6 = '-'; name7 = '-'; name8 = '-' ;
                goto ListOfTasks; notification = ""; break;

			// List of commands (help).
			case '?':
				std::cout << "┌───────────────────────────────────────────┐\n";
				std::cout << "│ l             - List of task.             │\n";
				std::cout << "│                   \033[1m---\033[0m                     │\n";
				std::cout << "│ g[ID]new_name - Rename task.              │\n";
				std::cout << "│ Action >> g1Feed the cat                  │\n";
				std::cout << "│                   \033[1m---\033[0m                     │\n";
                std::cout << "│ f[ID]status   - Change task status.       │\n";
				std::cout << "│ Action >> f1t                             │\n";
				std::cout << "│     t         - Start performing a task.  │\n";
				std::cout << "│     r         - Finish the task.          │\n";
				std::cout << "│     y         - Freeze the task           │\n";
				std::cout << "│                   \033[1m---\033[0m                     │\n";
				std::cout << "│ !             - Exit from the programm.   │\n";
				std::cout << "└───────────────────────────────────────────┘\n" << std::endl;
				break;

			// Exit.
			case '!':
				std::cout << "\033[34;1mExiting...  \n";
			    end = true; break;

			// Error.
			default:
				std::cout << "\033[1;31mAction is not valid! \033[1;31m(\033[0;31m눈\033[1;31m_\033[0;31m눈\033[1;31m)\033[0m\n" << std::endl;
                break;
		}
        
        // Notification if all tasks are done.
        if(points == 8) {
            if(stop == false) {notification = notification + "\033[1;93mGood job! Enter 'C' for clear tasks.\033[0m\n";}
            stop = true;
        }
	}
}
