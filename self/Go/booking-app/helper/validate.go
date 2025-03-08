package helper

import "strings"

// Capitalize the first letter to export the function.
func ValidateUser(fName string, lname string, email string, bookedTickets uint, remainingTickets uint) (bool,bool,bool) {
    var isValidName bool = (len(fName)>=2) && (len(lname)>=2)
    var isValidEmail bool = strings.Contains(email,"@")
    var isValidNoOfTickets bool = (bookedTickets>0) && (bookedTickets <= remainingTickets)
    return isValidName,isValidEmail,isValidNoOfTickets
}
