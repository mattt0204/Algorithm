++) {
      if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
        if (Jvis[i][j] == 0)
          result = Jvis[i][j] + 1;
    }
  }

  if (result == 0)
    cout << "IMPOSSIBLE";
  else
    cout << result;

  return 0;
}
