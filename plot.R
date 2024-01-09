#Author:  Sammed Sunil Admuthe

library(ggplot2)

filename <- "accountLog.txt"


data <- read.table(filename, header = FALSE, sep = " ",
                   col.names = c("TotalValue", "CashBalance", "Day", "Month", "Date", "Time", "Year"))
data$DateTime <- as.POSIXct(paste(data$Day, data$Month, data$Date, data$Time, data$Year), 
                            format = "%a %b %d %H:%M:%S %Y")
ggplot(data, aes(x = DateTime, y = TotalValue)) +
  geom_line() + 
  geom_point() +
  labs(title = "Portfolio Value Over Time", x = "Date and Time", y = "Total Portfolio Value") +
  theme_minimal()