#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    set<int> days;  // to keep track of unique days
    
    for (int i = 0; i < n; ++i) {
        int arr, dep;
        cin >> arr >> dep;
        events.emplace_back(arr, 1);  // arrival time +1 room
        events.emplace_back(dep + 1, -1);  // departure time +1 decrement
        days.insert(arr);
        days.insert(dep + 1);
    }
    
    sort(events.begin(), events.end());
    
    map<int, int> day_room_map;
    int current_rooms = 0;
    int max_rooms = 0;
    int i=0;
    for (const auto& event : events) {
        current_rooms += event.second;
        day_room_map[i++] = current_rooms;
        max_rooms = max(max_rooms, current_rooms);
    }
    
    cout << "Maximum number of rooms needed: " << max_rooms << endl;
    
    cout << "Rooms needed each day: " << endl;
    for (const auto& day : days) {
        cout << "Day " << day << ": " << day_room_map[day] << " rooms" << endl;
    }
    
    return 0;
}
