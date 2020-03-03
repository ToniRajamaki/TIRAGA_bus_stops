// Datastructures.cc

#include "datastructures.hh"

#include <random>
#include <cmath>
#include <stdexcept>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

double distance_from_origin(Coord c){
    return(sqrt( (c.x)*(c.x) + (c.y)*(c.y) ));
}




template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Replace this comment with your implementation
}

Datastructures::~Datastructures()
{
    // Replace this comment with your implementation
}

int Datastructures::stop_count()
{
    int number_of_stops = 0;
    number_of_stops = static_cast<int>(stops_.size());
    if(number_of_stops == 0){
        return NO_VALUE;
    }else{
        return number_of_stops;
    }
}

void Datastructures::clear_all()
{
    stops_.clear();
    stopIDs_.clear();
    // Replace this comment with your implementation
}

std::vector<StopID> Datastructures::all_stops()
{
    for(auto stop:stops_){
        stopIDs_.push_back(stop.first);
    }
    if(stopIDs_.size()==0){
        return {NO_STOP};
    }else{
        return stopIDs_;
    }
}

bool Datastructures::add_stop(StopID id, const Name& name, Coord xy)
{
    struct Stop stop = {id,name,xy};
    if(stops_.find(id)!=stops_.end()){
        return false;
    }
    stops_.insert({id,stop});

    return true;

}

Name Datastructures::get_stop_name(StopID id)
{

    if(stops_.find(id)!=stops_.end()){
        return stops_.at(id).Name;
    }else{
        return NO_NAME;
    }
}

Coord Datastructures::get_stop_coord(StopID id)
{

    if(stops_.find(id)!=stops_.end()){
        return stops_.at(id).Coord;
    }else{
        return NO_COORD;
    }
}

std::vector<StopID> Datastructures::stops_alphabetically()
{
    std::vector<Stop> vector_stops;
    std::vector<long int> ordered_stopIDs;

    for(auto stop : stops_){
        vector_stops.push_back(stop.second);
    }


    std::sort(vector_stops.begin(), vector_stops.end(),
              [](const Stop &a,const Stop &b){
        return a.Name<b.Name;
    });

    for(auto stop:vector_stops){
        ordered_stopIDs.push_back(stop.StopID);
    }
    if(ordered_stopIDs.size() == 0){
        return {NO_STOP};
    }else{
        return ordered_stopIDs;
    }

}

std::vector<StopID> Datastructures::stops_coord_order()
{


    std::vector<Stop> vector_stops;
    std::vector<long int> ordered_stopIDs;

    for(auto stop : stops_){
        vector_stops.push_back(stop.second);
    }

    std::sort(vector_stops.begin(), vector_stops.end(),
              [](const Stop &a,const Stop &b){
        return distance_from_origin(a.Coord)<distance_from_origin(b.Coord);
    });


    for(auto stop:vector_stops){
        ordered_stopIDs.push_back(stop.StopID);
    }
    if(ordered_stopIDs.size() == 0){
        return {NO_STOP};
    }else{
        return ordered_stopIDs;
    }

}

StopID Datastructures::min_coord()
{
    StopID stopId = -1;
    double min_distance = 1000;
    if(stops_.size()==0){
        return NO_STOP;
    }

    for(auto stop:stops_){
        if(distance_from_origin(stop.second.Coord)< min_distance){
            min_distance = distance_from_origin(stop.second.Coord);
            stopId = stop.first;
        }

    }return stopId;



}

StopID Datastructures::max_coord()
{
    StopID stopId = -1;
    double max_distance = -1;
    if(stops_.size()==0){
        return NO_STOP;
    }

    for(auto stop:stops_){
        if(distance_from_origin(stop.second.Coord)> max_distance){
            max_distance = distance_from_origin(stop.second.Coord);
            stopId = stop.first;
        }

    }return stopId;
}

std::vector<StopID> Datastructures::find_stops(Name const& name)
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

bool Datastructures::change_stop_name(StopID id, const Name& newname)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::change_stop_coord(StopID id, Coord newcoord)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::add_region(RegionID id, const Name &name)
{
    // Replace this comment and the line below with your implementation
    return false;
}

Name Datastructures::get_region_name(RegionID id)
{
    // Replace this comment and the line below with your implementation
    return NO_NAME;
}

std::vector<RegionID> Datastructures::all_regions()
{
    // Replace this comment and the line below with your implementation
    return {NO_REGION};
}

bool Datastructures::add_stop_to_region(StopID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    return false;
}

std::vector<RegionID> Datastructures::stop_regions(StopID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_REGION};
}

void Datastructures::creation_finished()
{
    // Replace this comment with your implementation
    // You don't have to use this method for anything, if you don't need it
}

std::pair<Coord,Coord> Datastructures::region_bounding_box(RegionID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_COORD, NO_COORD};
}

std::vector<StopID> Datastructures::stops_closest_to(StopID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

bool Datastructures::remove_stop(StopID id)
{
    // Replace this comment and the line below with your implementation
    return false;
}

RegionID Datastructures::stops_common_region(StopID id1, StopID id2)
{
    // Replace this comment and the line below with your implementation
    return NO_REGION;
}

