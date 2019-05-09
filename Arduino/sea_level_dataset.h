// mean sea level anomaly global ocean (66°S to 66*N - with Annual signal removed)
//institution = NOAA/Laboratory for Satellite Altimetry 
//references = NOAA Sea Level Rise (http://www,star,nesdis,noaa,gov/sod/lsa/SeaLevelRise/) and Radar Altimeter Database System (http://www,deos,tudelft,nl/altim/rads/) 
//comment = Data use policy: In publications
//trend = 2,88 mm/year (no glacial isostatic adjustment correction) 

//alternative links
// https://www.star.nesdis.noaa.gov/sod/lsa/SeaLevelRise/LSA_SLR_timeseries_global.php
// http://coloringclimate.com/docs/ocean.html

const int NUMRECORDS = 26;
int years[]    = {1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018};
float values[] = {-17.09, -13.56, -9.98, -6.63, -4.94, -5.37, -3.62, -1.38, 3.56, 7.20, 11.14, 12.38, 14.66, 17.91, 17.77, 21.74, 25.41, 26.77, 25.16, 35.53, 37.82, 40.72, 49.46, 52.32, 53.64, 57.10};
float MINIMUM = -17.09;
float MAXIMUM = 57.10;
