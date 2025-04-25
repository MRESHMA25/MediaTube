#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>

// Forward declaration of Media so that we can use pointers in the matches function.
class Media;

class Search {
public:
    // Pure virtual function to determine if a given Media matches the search criteria.
    virtual bool matches(const Media* media) const = 0;
    
    // Pure virtual function to print the search criteria to an ostream.
    virtual void print(std::ostream& ost) const = 0;
    
    // Virtual destructor
    virtual ~Search() {}
};

// Overload the stream insertion operator to work with Search objects polymorphically.
inline std::ostream& operator<<(std::ostream& ost, const Search& s) {
    s.print(ost);
    return ost;
}

// O_Search: Matches Media by the channel owner.
class O_Search : virtual public Search {
protected:
    std::string owner;
public:
    // Constructor takes a string to initialize the owner.
    O_Search(const std::string& owner);
    
    // Returns true if the Media's owner matches the stored owner.
    virtual bool matches(const Media* media) const;
    
    // Prints the search criteria (owner).
    virtual void print(std::ostream& ost) const;
};

// C_Search: Matches Media by the category.
class C_Search : virtual public Search {
protected:
    std::string category;
public:
    // Constructor takes a string to initialize the category.
    C_Search(const std::string& category);
    
    // Returns true if the Media's category matches the stored category.
    virtual bool matches(const Media* media) const;
    
    // Prints the search criteria (category).
    virtual void print(std::ostream& ost) const;
};

// OorC_Search: Matches Media if either the owner OR the category match.
class OorC_Search : public O_Search, public C_Search {
public:
    // Constructor takes an owner and a category (in that order) and initializes both.
    OorC_Search(const std::string& owner, const std::string& category);
    
    // Returns true if the Media's owner matches or the Media's category matches.
    virtual bool matches(const Media* media) const;
    
    // Prints the search criteria (both owner and category).
    virtual void print(std::ostream& ost) const;
};

#endif // SEARCH_H
