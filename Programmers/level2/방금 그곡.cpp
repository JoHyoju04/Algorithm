#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string change(string &in, map<string, char> &s)
{
    string out = "";
    
    for(int i = 0; i < in.size(); i++)
    {
        if(in[i + 1] == '#')
        {
            out += s[in.substr(i, 2)];
            i++;
        }
         else
            out += in[i];
    }
    return out;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int sHour = 0, eHour = 0, sMin = 0, eMin = 0, time = 0, maxTime = 0;
    string melody = "", title = "";
    map<string, char> s;
    
    s["C#"] = 'Q';
    s["D#"] = 'W';
    s["F#"] = 'R';
    s["G#"] = 'T';
    s["A#"] = 'Y';
    
    melody = change(m, s);
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string tmp = "", music = "";
        
        sHour = stoi(musicinfos[i].substr(0, 2)) * 60;
        sMin = stoi(musicinfos[i].substr(3, 2));
        eHour = stoi(musicinfos[i].substr(6, 2)) * 60;
        eMin = stoi(musicinfos[i].substr(9, 2));
        time = (eHour + eMin) - (sHour + sMin);
        
        //Divide title and Melody from musicinfos
        //tmp == melody
        for(int j = 12; musicinfos[i].size(); j++)
        {
            if(musicinfos[i][j] == ',')
            {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);
                break;
            }
        }
        
        music = change(tmp, s);

        if(music.size() < time)
        {
            tmp = music;
        
            for(int j = 1; j < time / tmp.size(); j++)
                music += tmp;
            for(int j = 0; j < time % tmp.size(); j++)
                music += tmp[j];
        }
        else
            music = music.substr(0, time);
        
        if(music.find(melody) != -1)
        {
            if(maxTime < time)
            {
                answer = title;
                maxTime = time;
            }
        }
    }
    return answer;
}