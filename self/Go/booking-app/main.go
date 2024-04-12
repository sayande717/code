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

    var userTickets uint

    // Minimal definition
    //temp := 20

    // Array definition
    // var bookings = [50]string{"AAA","BBB","CCC"}
    //var bookings [50]string

    // Slice definition
    var bookings []string

    var temp = [50]string{"AAA","BBB"}

    fmt.Printf("%v",temp)
    
    // Printing variables, spaces get added automatically
    fmt.Printf("Welcome to %v Booking Application\n",conferenceName) // f=format
    
    fmt.Println("Welcome to", conferenceName, "Booking Application. We have",remainingTickets,"tickets out of",conferenceTickets, "available.")
    fmt.Println("Get your tickets here!")

    //for {
        // statement
    //}

    // Taking user input 
    fmt.Print("Enter your first name: ")
    fmt.Scan(&firstName) 

    fmt.Print("Enter your last name: ")
    fmt.Scan(&lastName)
    
    // Insert in an array
    // bookings[0] = firstName + " " + lastName

    // Append to a slice
    bookings = append(bookings,firstName + " " + lastName)

    fmt.Print("Enter the number of tickets you need: ")
    fmt.Scan(&userTickets)

    remainingTickets = remainingTickets - userTickets

    fmt.Printf("User %v %v booked %v tickets.\n",firstName,lastName,userTickets)
    fmt.Printf("%v tickets remain at this point.",remainingTickets)
    //fmt.Printf("username is of type %T.",userName)
    
    // Using for loop
    //for index,element := range bookings { // statements }

    var firstNames []string
    for _,element := range bookings {
        firstNames = append(firstNames,strings.Fields(element)[0])
    }

    // Print an array/slice
    fmt.Printf("\nThese are all the bookings: %v",bookings)
    fmt.Printf("\nThese are the first names: %v",firstNames)
}
