package main
import (
    "fmt"
    "strings"
)

func main() {
    // Variables
    var conferenceName string = "Go Conference" // variable
    const conferenceTickets = 50         // Constants
    var remainingTickets uint = 50
    // Variables without value
    var firstName string
    var lastName string
    var email string
    var userTickets uint

    // Slice definition
    var firstNames []string
    var bookings []string

    // Minimal definition
    //temp := 20

    // Array definition
    // var bookings = [50]string{"AAA","BBB","CCC"}
    //var bookings [50]string

        
    // Welcome message
    fmt.Printf("Welcome to %v Booking Application\n",conferenceName) // f=format
    
    fmt.Println("Welcome to", conferenceName, "Booking Application. We have",remainingTickets,"tickets out of",conferenceTickets, "available.")
    fmt.Println("Get your tickets here!")

    for (remainingTickets > 0) {
        // Taking user input 
        fmt.Print("\nEnter your first name: ")
        fmt.Scan(&firstName)

        fmt.Print("Enter your last name: ")
        fmt.Scan(&lastName)
        
        fmt.Print("Enter the e-mail address you want the ticket to be sent: ")
        fmt.Scan(&email)
    
        fmt.Print("Enter the number of tickets you need: ")
        fmt.Scan(&userTickets)
    

        var isValidName bool = (len(firstName)>=2) && (len(lastName)>=2)
        var isValidEmail bool = strings.Contains(email,"@")
        var isValidNoOfTickets bool = (userTickets>0) && (userTickets <= remainingTickets)

        if(isValidName && isValidEmail && isValidNoOfTickets) {
            remainingTickets = remainingTickets - userTickets

            // Append to a slice
            bookings = append(bookings,firstName + " " + lastName)
            firstNames = append(firstNames,firstName)
    
                fmt.Printf("\nUser %v %v booked %v tickets.",firstName,lastName,userTickets)
            fmt.Printf("\n%v tickets remain at this point.",remainingTickets)
        } else {
            fmt.Println("Input data is invalid. Please try again.")
            continue;
        }
    
        // Print an array/slice
        fmt.Printf("\nThese are all the bookings: %v",bookings)
        fmt.Printf("\nThese are the first names: %v",firstNames)
    }

    fmt.Print("\n0 tickets remain.")
}
