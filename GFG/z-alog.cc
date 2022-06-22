int zAlgorithm(string s, string p, int n, int m)
{
	int count = 0, l = 0, r = 0, pos;
	string c = p + "#" + s;
	int k = c.length();
	
	// Making an array(z array) of length K
	int zarr[k];
	zarr[0] = 0;
	for (int i = 1; i < k; i++)
	{
		if (i > r)
		{
	
			// Resetting L and R
			l = i;
			r = i;
	
			// Calulting z[i]
			while (r < k and c[r - l] == c[r] )
			{
				r++;
			}

			zarr[i] = (r--) - l;
			
			// Checking if this zarr[i] is equal to the length of p or not.
			if (zarr[i] == m)
			{
				count++;
			}

		}

		else
		{
			int pos = i - l;

			if (zarr[pos] < r - i + 1)
			{
				zarr[i] = zarr[pos];
	
				// Checking if this zarr[i] is equal to the length of p or not.
				if (zarr[i] == m)
				{
					count++;
				}

			}

			else
			{
				l = i;
	
				// Calulting z[i]
				while (r < k and c[r - l] == c[r])
				{
					r++;
				}

				zarr[i] = (r--) - l;
	
				// Checking if this zarr[i] is equal to the length of p or not.
				if (zarr[i] == m)
				{
					count++;
				}

			}
		}
	}

	return count;
}


coding ninja
