module.exports = {
  presets: ['expo'],
  plugins: [
    [
      'module-resolver',
      {
        alias: {
          'bs-react-navigation': '../../nav-c',
        },
      },
    ],
  ],
};
