**Team Win/Loss**

This assignment processes structured football team data from a text file, calculates each team's win/loss differential, and demonstrates basic C++ programming concepts such as:

- Structs
- File I/O
- Dynamic memory allocation (new[], delete[])
- Function decomposition
- Looping and string handling

---

g++ -std=c++11 -O2 team_stats.cpp -o team_stats


g++ -std=c++11 -O2 team_stats_organized.cpp -o team_stats_organized


*Run the basic version:*

./team_stats


*Run the organized version:*

./team_stats_organized


You will be prompted to enter the input filename. 

Please enter the name of the input file.
Filename: data.txt


*Output from team_stats*

-10
14
2
4
-2
6
-8


*Output from team_stats_organized*

Team New England Patriots has win: 3 and 13 losses, then win/loss differential is -10
Team Buffalo Bills has win: 15 and 1 losses, then win/loss differential is 14
Team Carolina Panthers has win: 9 and 7 losses, then win/loss differential is 2
Team Jacksonville Jaguars has win: 10 and 6 losses, then win/loss differential is 4
Team Miami Dolphins has win: 7 and 9 losses, then win/loss differential is -2
Team Green Bay Packers has win: 11 and 5 losses, then win/loss differential is 6
Team San Francisco 49ers has win: 4 and 12 losses, then win/loss differential is -8



