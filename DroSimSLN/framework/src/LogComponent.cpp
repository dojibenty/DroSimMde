#include "LogComponent.h"
#include <iostream>
//pyp
LogComponent::LogComponent(string filename, double aFrequency) : TimeableObject( aFrequency) {
		try {
			string path = filePath( filename);
			outputFile = ofstream( path);
			//dataWriterBuffer = new BufferedWriter(outputFile);
			cout << "LogComponent creation fichier csv : " << path << endl;
			open();
		} catch (exception &e) {
			// TODO Auto-generated catch block
			cout << e.what() << endl;
		}
		counter = 0;
		usage = 0;
	}
LogComponent::~LogComponent(){}
string LogComponent::filePath( string filename ) {
	string s = filename + ".csv";
	string str = "C:\\EclipseProjects\\CppTests\\SwimmerEx\\data\\results\\" + s;
	/*
	try {
		String path = new java.io.File(".").getCanonicalPath();
		if (OS.isWindows()) {
			path = path + "\\data\\results\\";//"\\data\\hdf5\\"
		  } else if (OS.isLinux()) {
			 //cmd = properties.getProperty("gdalPath") + "/" + command;
				path = path + "/data/results/";//"\\data\\hdf5\\"
		  } else {
			  System.out.println("OS not supported");
		  }
		return path + filename + ".csv";
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		return "";
	}
	*/
	return str;
	}

void LogComponent::open() {
		counter = 0;
		usage++;
	}
void LogComponent::WriteFirstLine() {}
	

bool LogComponent::close() {
		if (usage <= 1) {
			try {
				outputFile << "\n";
			} catch (exception &e) {
				cerr << e.what() << endl;
			}
			//if (outputFile != 0) {
				try {
					outputFile.close();
				} catch (exception &e) {
					cerr << e.what() << endl;
					return false;
				}
			//}
		}
		return (usage == 1);
	}

void LogComponent::writeNames(string names) {
/*
		String theNames = "";
		for (String name : names) {
			theNames += name + ";";
		}
		this.write(theNames);
		*/
	outputFile << names << ";";
	}

void LogComponent::writeNewValues(double values) {
	/*
		String theValues = "";
		if (frequency == 1 || counter == 0) {
			for (Double value : values) {
				theValues += value + ";";
			}
			this.write(theValues);
		}*/
	outputFile << values << ";";
	}

void LogComponent::writeNewValues(long values) {
	/*
		String theValues = "";
		if (frequency == 1 || counter == 0) {
			for (Long value : values) {
				theValues += value + ";";
			}
			this.write(theValues);
		}*/
	outputFile << values << ";";
	}

void LogComponent::write(string value) {
	/*
		if (counter == 0 && usage <= 1) {
			try {
				dataWriterBuffer.write(value);
				dataWriterBuffer.flush();
			} catch (IOException e) {
				System.err.println("(OUTPUTFILE) Failed to Write");
			}
		}*/
	outputFile << value ;
	}

void LogComponent::endLine() {
	outputFile << endl ;
	/*ù
		if (counter == 0 && usage <= 1) {
			try {
				dataWriterBuffer.write("\n");
				dataWriterBuffer.flush();
			} catch (IOException e) {
				System.err.println("(OUTPUTFILE) Failed to Write");
			}
		}
		counter++;
		if (counter == frequency) {
			counter = 0;
		}*/
	}


void LogComponent::timeStamp(long currentMS) {
		if (counter == 0 && usage <= 1) {
			writeNewValues(currentMS);
		}
	}
