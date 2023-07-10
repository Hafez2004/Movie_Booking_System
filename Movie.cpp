#include "Movie.h"
bool Movie::isFound(str title_)
{
	auto title = find(Title.begin(), Title.end(), title_);
	if (title != Title.end())
		return true; // found
	else
		return false; // not found
}

bool Movie::isGenre(str genre_)
{
	auto it = find(movieGenres.begin(), movieGenres.end(), genre_);
	if (it != movieGenres.end()) // found
		return true;
	else // not found
		return false;
}

bool Movie::Validate(int release_)
{
	if (release_ >= 1900 && release_ <= 2023)
		return true;
	else
		return false;
}

bool Movie::Validate(fl price_)
{
	if (price_ >= 0)
		return true;
	else
		return false;
}

int Movie::indexMovie(str title_)
{
	auto it = find(Title.begin(), Title.end(), title_);
	int index = distance(Title.begin(), it);
	return index;
}

void Movie::addMovie()
{
		str title, genre, country, confirm;
		int release;
		fl ticket;
	do {
		cout << space << "\t[Add Movie]\n";
		cout << "\t_________________________________________________\n\n";
		cout << space << "     Title    : ", cin >> title;
		cout << space << "     Genre    : ", cin >> genre;
		cout << space << "    Country   : ", cin >> country;
		cout << space << " Release Date : ", cin >> release;
		cout << space << " Ticket Price : ", cin >> ticket;
		if (isFound(title) || !isGenre(genre) || !Validate(release) || !Validate(ticket))
		{
			cout << space << "\t[Invalid Data]\n";
			if (isFound(title))
				cout << space << title << " has already been added\n";
			if (!isGenre(genre))
				cout << space << genre << " is Invalid Genre\n";
			if (!Validate(release))
				cout << space << release << " is Invalid Date\n";
			if (!Validate(ticket))
				cout << space << ticket << " is Invslid Price\n";
			Sleep(4000);
			cls;
		}
	} while (isFound(title) || !isGenre(genre) || !Validate(release) || !Validate(ticket));
	cout << br;
	cout << space << "  Confirm : ", cin >> confirm;
	if (confirm == "no" || confirm == "NO" || confirm == "No")
	{
		cout << space << "\t[Cancelled]\n";
		Sleep(3000);
		cls;
	}
	else
	{
		Title.push_back(title);
		Genre.push_back(genre);
		Country.push_back(country);
		ReleaseDate.push_back(release);
		TicketPrice.push_back(ticket);
		cout << space << "\t[Done]\n";
		Sleep(2000);
		cls;
	}
}

void Movie::delMovie()
{
	str title, confirm;
	cout << space << "\t[Delete Movie]\n";
	cout << "\t_________________________________________________\n\n";
	do {
		cout << space << "     Title    : ", cin >> title;
		if (!isFound(title))
		{
			cout << space << "\t[ERROR]\n";
			cout << space << title << " is not found\n";
			Sleep(4000);
			cls;
		}
	} while (!isFound(title));

	cout << br;
	cout << space << "  Confirm : ", cin >> confirm;
	if (confirm == "no" || confirm == "NO" || confirm == "No")
	{
		cout << space << "\t[Cancelled]\n";
		Sleep(3000);
		cls;
	}
	else
	{
		int location = indexMovie(title);
		Title.erase(Title.begin() + location);
		Genre.erase(Genre.begin() + location);
		Country.erase(Country.begin() + location);
		ReleaseDate.erase(ReleaseDate.begin() + location);
		TicketPrice.erase(TicketPrice.begin() + location);
		cout << space << "\t[Done]\n";
		Sleep(2000);
		cls;
	}
}

void Movie::allMovies()
{
	str confirm;
	cout << space << "\t[All Movies]\n";
	cout << "\t_________________________________________________\n\n";
	for (int i = 0; i < Title.size(); i++)
		cout << space << i + 1 << ' ' << Title[i] << "  " << Genre[i] << "  " << ReleaseDate[i] << br;
	cout << "\tTotal Movies : " << Title.size() << br;
	cout << "\t_________________________________________________\n\n";
	cout << "\t@: ", cin >> confirm;
	cls;
}

void Movie::searchMovie()
{
	str choice;

	cout << space << "\t[Search]\n";
	cout << "\t_________________________________________________\n\n";
	cout << "\t1 Title\n" << "\t2 Genre\n" << "\t3 Release-Date\n";
	cout << "\t@: ", cin >> choice;
	if (choice == "1" || choice == "Title")
	{
		cls;
		str title, confirm;
		do {
			cout << space << "     Title    : ", cin >> title;
			if (!isFound(title))
			{
				cout << space << "\t[ERROR]\n";
				cout << space << title << " is not found\n";
				Sleep(4000);
				cls;
			}
		} while (!isFound(title));
		cls;
		int index = indexMovie(title);
		cout << space << "\t[" << Title[index] << "]\n";
		cout << space << "     Genre    : " << Genre[index] << br;
		cout << space << "    Country   : " << Country[index] << br;
		cout << space << " Release Date : " << ReleaseDate[index] << br;
		cout << space << " Ticket Price : " << TicketPrice[index] << br;
		cout << "\t_________________________________________________\n\n";
		cout << "\t@: ", cin >> confirm;
		cls;
	}
	elif(choice == "2" || choice == "Genre")
	{
		cls;
		str genre, confirm;
		do {
			cout << space << "     Genre    : ", cin >> genre;
			if (!isGenre(genre))
			{
				cout << space << "\t[ERROR]\n";
				cout << space << genre << " is Invalid\n";
				Sleep(4000);
				cls;
			}
		} while (!isGenre(genre));
		cls;
		cout << space << "\t[" << genre << "]\n";
		if (find(Genre.begin(), Genre.end(), genre) != Genre.end())
		{
			for (int i = 0; i < Genre.size(); i++)
			{
				if (Genre[i] == genre)
					cout << space << i + 1 << ' ' << Title[i] << "  " << Genre[i] << "  " << ReleaseDate[i] << br;
			}
		}
		else
			cout << space << genre << "is Empty..\n";
		cout << "\t_________________________________________________\n\n";
		cout << "\t@: ", cin >> confirm;
		cls;
	}
	elif(choice == "3" || choice == "Release-Date" || choice == "release")
	{
		cls;
		str confirm;
		int from, to;
		do {
			cout << space << "\t[TimeLine]\n";
			cout << space << "     From    : ", cin >> from;
			cout << space << "	    To	   : ", cin >> to;
			if (!Validate(from) || !Validate(to) || from > to)
			{
				cout << space << "\t[ERROR]\n";
				cout << space << "Invalid TimeLine\n";
				Sleep(4000);
				cls;
			}
		} while (!Validate(from) || !Validate(to) || from > to);
		if (find(ReleaseDate.begin(), ReleaseDate.end(), from) != ReleaseDate.end() || find(ReleaseDate.begin(), ReleaseDate.end(), to) != ReleaseDate.end())
		{
			for (int i = 0; i < ReleaseDate.size(); i++)
				if(ReleaseDate[i] >= from && ReleaseDate[i] <= to)
					cout << space << i + 1 << ' ' << Title[i] << "  " << Genre[i] << "  " << ReleaseDate[i] << br;
		}
		else
			cout << space << "The TimeLine is Empty..\n";
		cout << "\t_________________________________________________\n\n";
		cout << "\t@: ", cin >> confirm;
		cls;
	}
}