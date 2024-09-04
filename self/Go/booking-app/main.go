package main
import (
    "fmt"
    // Syntax to import the helper package
    "booking-app/helper"
    "strconv"
)

// Global variables
// Slice definition
var firstNames []string
// Init a list with map inside
var bookings = make([]map[string]string,0)

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
    
    var isValidName,isValidEmail,isValidNoOfTickets bool

    // Minimal definition
    //temp := 20

    // Array definition
    // var bookings = [50]string{"AAA","BBB","CCC"}
    //var bookings [50]string

    greetUser(conferenceName,conferenceTickets,remainingTickets)

    for (remainingTickets > 0) {

        // take input
        firstName,lastName,email,userTickets = takeUserInput(remainingTickets)

        // validate
        isValidName, isValidEmail, isValidNoOfTickets = helper.ValidateUser(firstName,lastName,email,userTickets,remainingTickets)

        if(isValidName && isValidEmail && isValidNoOfTickets) {
            remainingTickets = remainingTickets - userTickets

            bookTickets(firstName,lastName,email,userTickets)

            fmt.Printf("\nUser %v %v booked %v tickets.",firstName,lastName,userTickets)
            fmt.Printf("\n%v tickets remain at this point.",remainingTickets)
        } else {
            if(!isValidName) {
                fmt.Println("Please enter a valid name")
            }
            if(!isValidEmail) {
                fmt.Println("Please enter a valid e-mail address")
            }
            if(!isValidNoOfTickets) {
                fmt.Println("Please enter a valid number of tickets.")
            }   

            continue;
        }

        // Print an array/slice
        fmt.Printf("\nThese are all the bookings: %v",bookings)
        fmt.Printf("\nThese are the first names: %v",firstNames)
    }

    fmt.Print("\n0 tickets remain.")
}

func greetUser(conferenceName string,conferenceTickets int,remainingTickets uint) {
    fmt.Println("Welcome to", conferenceName, "Booking Application. We have",remainingTickets,"tickets out of",conferenceTickets, "available.")
    fmt.Println("Get your tickets here!")
}

func takeUserInput(remainingTickets uint) (string,string,string,uint) {

    var fname string
    var lname string
    var email string
    var userTickets uint
        
    // Taking user input 
    fmt.Print("\nEnter your first name: ")
    fmt.Scan(&fname)

    fmt.Print("Enter your last name: ")
    fmt.Scan(&lname)
        
    fmt.Print("Enter the e-mail address you want the ticket to be sent: ")
    fmt.Scan(&email)
    
    fmt.Print("Enter the number of tickets you need: ")
    fmt.Scan(&userTickets)

    return fname,lname,email,userTickets
}

func bookTickets(firstName string, lastName string, email string, userTickets uint) {
    // Putting data in a map
    var userData = make(map[string]string)
    userData["firstName"] = firstName
    userData["lastName"] = lastName
    userData["email"] = email
    // format uint to string.
    // Type: UInt64, Base 10 ie Decimel number.
    userData["userTickets"] = strconv.FormatUint(uint64(userTickets),10)
    // appending the map in a Slice
    bookings = append(bookings,userData)
}