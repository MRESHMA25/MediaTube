#include "Search.h"
#include "Media.h"

// O_Search implementation
O_Search::O_Search(const std::string& owner) : owner(owner) {}

bool O_Search::matches(const Media* media) const {
    return (media->getOwner() == owner);
}

void O_Search::print(std::ostream& ost) const {
    ost << "Owner Search: matches Media with owner '" << owner << "'";
}

// C_Search implementation
C_Search::C_Search(const std::string& category) : category(category) {}

bool C_Search::matches(const Media* media) const {
    return (media->getCategory() == category);
}

void C_Search::print(std::ostream& ost) const {
    ost << "Category Search: matches Media with category '" << category << "'";
}

// OorC_Search implementation
OorC_Search::OorC_Search(const std::string& owner, const std::string& category)
    : O_Search(owner), C_Search(category) {}

bool OorC_Search::matches(const Media* media) const {
    // Return true if either the owner or the category of the Media matches.
    return (media->getOwner() == owner) || (media->getCategory() == category);
}

void OorC_Search::print(std::ostream& ost) const {
    ost << "Owner or Category Search: matches Media with owner '" << owner 
        << "' or category '" << category << "'";
}
