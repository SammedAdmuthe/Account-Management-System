#Author:  Sammed Sunil Admuthe

# Load necessary libraries
library(ggplot2)

# Define the file path (change this to your file's path)
filename <- "accountLog.txt"

# Read data from the file
# Adjust the number of columns in 'colClasses' and 'col.names' based on your file's format
data <- read.table(filename, header = FALSE, sep = " ",
                   col.names = c("TotalValue", "CashBalance", "Day", "Month", "Date", "Time", "Year"))
# Combine the date and time columns into a single datetime column
data$DateTime <- as.POSIXct(paste(data$Day, data$Month, data$Date, data$Time, data$Year), 
                            format = "%a %b %d %H:%M:%S %Y")
# Plotting
ggplot(data, aes(x = DateTime, y = TotalValue)) +
  geom_line() +  # Line connecting points
  geom_point() +  # Points at each data entry
  labs(title = "Portfolio Value Over Time", x = "Date and Time", y = "Total Portfolio Value") +
  theme_minimal()