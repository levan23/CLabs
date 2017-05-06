
typedef struct movie{
	int movieCode;
	char *name;
	int year;
	int length;
	char *director;
}movie;

typedef struct rating{
	int reviewId;
	int movieCode;
	char *reviewerName;
	char *status;
	float movieRating;
}rating;

movie *readMovies(int *movieCount);
rating *readRatings(int *ratingCount);

