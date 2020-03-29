// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <list>
#include <unordered_map>
#include <algorithm>


// Types for IDs
using StopID = long int;
using RegionID = std::string;
using Name = std::string;

// Return values for cases where required thing was not found
StopID const NO_STOP = -1;
RegionID const NO_REGION = "!!NO_REGION!!";

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();

// Return value for cases where name values were not found
Name const NO_NAME = "!!NO_NAME!!";

// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

// Example: Defining < for Coord so that it can be used
// as key for std::map/set
inline bool operator<(Coord c1, Coord c2)
{
    if (c1.y < c2.y) { return true; }
    else if (c2.y < c1.y) { return false; }
    else { return c1.x < c2.x; }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};


// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();



    //     * O(1)
    //     * According to documentatioin unordered_map size algorithm is O(1).
    int stop_count();



    //     * O(n)
    //     * linear in the size of the containers
    void clear_all();



    //     * O(n)
    //     * linear in the size of the containers
    std::vector<StopID> all_stops();



    //     * O(N), Θ(1)
    //     * function uses two algorithms (find and insert) which are
    //     * both O(N),Θ(1).
    bool add_stop(StopID id, Name const& name, Coord xy);



    //     * O(N), Θ(1)
    //     * function uses (find and at) algorithms that are both O(N), Θ(1)
    Name get_stop_name(StopID id);



    //     * O(N), Θ(1)
    //     * function uses (find and at) algorithms that are both O(N), Θ(1)
    Coord get_stop_coord(StopID id);



    //     * O(N*log(N))
    //     * Includes two seperate for loops that are O(N)
    //     * and std::sort that is nlogn
    std::vector<StopID> stops_alphabetically();



    //     * O(N*log(N))
    //     * Includes two seperate for loops that are O(N)
    //     * and std::sort that is nlogn
    std::vector<StopID> stops_coord_order();



    //     * O(N)
    //     * Linear to size of stl
    StopID min_coord();



    //     * O(N)
    //     * Linear to size of stl
    StopID max_coord();



    //     * O(N)
    //     * Linear to size of stl
    std::vector<StopID> find_stops(Name const& name);



    //     * O(N), Θ(1)
    //     * function uses (find and at) algorithms that are both O(N), Θ(1)
    bool change_stop_name(StopID id, Name const& newname);



    //     * O(N), Θ(1)
    //     * function uses (find and at) algorithms that are both O(N), Θ(1)
    bool change_stop_coord(StopID id, Coord newcoord);



    //     * O(N), Θ(1)
    //     * function uses two algorithms (find and insert) which are both O(N),
    //     * Θ(1).
    bool add_region(RegionID id, Name const& name);



    //     * O(N), Θ(1)
    //     * function uses two algorithms (find and at) which are both O(N),Θ(1)
    Name get_region_name(RegionID id);



    //     * O(N)
    //     * Linear to size of stl
    std::vector<RegionID> all_regions();



    //     * O(N), Θ(1)
    //     * function uses two algorithms (find and at) which are both O(N),Θ(1)
    bool add_stop_to_region(StopID id, RegionID parentid);



    //     * O(N), Θ(1)
    //     * function uses two algorithms (find and at) which are both O(N),Θ(1)
    bool add_subregion_to_region(RegionID id, RegionID parentid);




    //     * O(N)
    //     * Linear to size of stl
    std::vector<RegionID> stop_regions(StopID id);




    // Non-compulsory operations

    void creation_finished();

    std::pair<Coord, Coord> region_bounding_box(RegionID id);

    std::vector<StopID> stops_closest_to(StopID id);


    bool remove_stop(StopID id);


    RegionID stops_common_region(StopID id1, StopID id2);

private:


    struct Stop{
        StopID stopID;
        Name name;
        Coord coord;
        RegionID belongsToRegion = NO_REGION;
    };



    struct Region{
        Name name;
        RegionID parentRegion = NO_REGION;
        std::vector<StopID> stops = {};
        std::vector<RegionID> subRegions = {}; //children
    };




    std::unordered_map<RegionID,Region> regions_;
    std::vector<RegionID> regionIDs_;

    std::unordered_map<StopID,Stop> stops_;
    std::vector<StopID> stopIDs_;

    std::vector<StopID> orderedStopIDsByName;

};

#endif // DATASTRUCTURES_HH
