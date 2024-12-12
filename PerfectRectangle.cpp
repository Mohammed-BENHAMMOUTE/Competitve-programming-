class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        struct Event {
            int x, y1, y2, type;
            bool operator<(const Event& e) const {
                if (x != e.x) return x < e.x;
                return type < e.type; // Process entering before exiting
            }
        };

        vector<Event> events;
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        long long area = 0;

        // Create events and calculate total area and bounding box
        for (auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1];
            int x2 = rect[2], y2 = rect[3];
            events.push_back({x1, y1, y2, 1});  // Entering event
            events.push_back({x2, y1, y2, -1}); // Exiting event
            area += (long long)(x2 - x1) * (y2 - y1);
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
        }

        // Check total area
        if (area != (long long)(maxX - minX) * (maxY - minY)) return false;

        // Sort events by x-coordinate
        sort(events.begin(), events.end());

        map<int, int> active;

        // Process events
        for (size_t i = 0; i < events.size(); ++i) {
            int x = events[i].x;
            // Process all events at the same x
            while (i < events.size() && events[i].x == x) {
                auto e = events[i];
                if (e.type == 1) {
                    // Check for overlaps
                    auto it = active.lower_bound(e.y1);
                    if (it != active.end() && it->first < e.y2) return false;
                    if (it != active.begin()) {
                        --it;
                        if (it->second > e.y1) return false;
                    }
                    active[e.y1] = e.y2;
                } else {
                    // Remove interval
                    active.erase(e.y1);
                }
                ++i;
            }
            --i; // Adjust for outer loop increment
        }

        return true;
    }
};